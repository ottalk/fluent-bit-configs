#!/usr/bin/python3

import schedule
import time
import datetime
import uuid
import requests
import json
import yaml
from flask import Flask, request
from multiprocessing import Process
import sys
import getopt
import argparse


app = Flask(__name__)
t = None
job_timer = None

def check_feed():
    global current_feed_count_9998
    global feed_9998_status

    response = requests.get(feed_metrics_url_9998)
    if response.status_code == 200:
        response_json = json.loads(response.content)
        input_record_count=response_json['input']['tcp.0']['records']
        print("input records count: ",input_record_count)
        current_feed_count_9998 = int(requests.get("http://localhost:59998/get_feed_count_9998").content)
        print("current_feed_count_9998=",current_feed_count_9998)
        if input_record_count > current_feed_count_9998:
            feed_9998_status="UP"
        else:
            feed_9998_status="DOWN"
        requests.get("http://localhost:59998/set_feed_count_9998/"+str(input_record_count))
    else:
        print("fluent-bit tcp endpoint unavailable")
        feed_9998_status="DOWN"
    print("feed_9998_status: ",feed_9998_status)
    response = requests.get("http://localhost:59998//set_feed_status/"+feed_9998_status)


def run_job(id):
    """ sample job with parameter """
    global job_timer
    print("timer job id={}".format(id))
    print("timer: {:.4f}sec".format(time.time() - job_timer))
    job_timer = time.time()
    check_feed()
   


def run_schedule():
    """ infinite loop for schedule """
    global job_timer
    job_timer = time.time()
    while 1:
        schedule.run_pending()
        time.sleep(1)

@app.route('/get_feed_status')
def status():
    global feed_9998_status
    return feed_9998_status

@app.route('/set_feed_count_9998/<string:count>')
def set_feed_count_9998(count):
    global current_feed_count_9998
    current_feed_count_9998=count
    return current_feed_count_9998

@app.route('/get_feed_count_9998')
def get_feed_count_9998():
    global current_feed_count_9998
    return str(current_feed_count_9998)

@app.route('/set_feed_status/<string:status>')
def set_feed_status(status):
    global feed_9998_status
    feed_9998_status = status
    return feed_9998_status


def main(argv):
    configfile = ''
    site = ''
    try:
        opts, args = getopt.getopt(argv,"h:c:s:",["configfile=","site="])
    except getopt.GetoptError:
        print ('ERROR: monitor_site.py -c <configfile>.yaml -s <sitename>')
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print ('INFO: monitor_site.py -c <configfile>.yaml -s <sitename>')
            sys.exit()
        elif opt in ("-c", "--config"):
            configfile = arg
        elif opt in ("-s", "--site"):
            site = arg
    if (configfile!='' and site!=''):
        return configfile,site
    else:
        print ('ERROR: monitor_site.py -c <configfile>.yaml -s <sitename>')
        sys.exit(2)

if __name__ == '__main__':
    configfile,site=main(sys.argv[1:])
    print ('configfile: ', configfile, ' ,site:',site)

    try:
        with open(configfile, 'r') as configfile_ro:
            cfg = yaml.full_load(configfile_ro)
    except FileNotFoundError:
        print("ERROR: cannot open '"+configfile+"'")

    #with open("config.yml", "r") as ymlfile:
    #cfg = yaml.load(ymlfile)

    #for section in cfg:
    #    print(section)
    print(cfg["monitor"][site])
    #print(cfg["controller"])


"""
    feed_metrics_url_9998="http://localhost:2020/api/v1/metrics"

    current_feed_count_9998 = 0

    feed_9998_status = "DOWN"


    nsec=10
    schedule.every(nsec).seconds.do(run_job, str(uuid.uuid4()))
    t = Process(target=run_schedule)
    t.start()
    app.run(host='0.0.0.0', port=59998)
"""