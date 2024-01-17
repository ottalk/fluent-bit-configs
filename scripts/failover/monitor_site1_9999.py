#!/usr/bin/python3

import schedule
import time
import datetime
import uuid
import requests
import json

from flask import Flask, request
from multiprocessing import Process

feed_metrics_url_9999="http://localhost:2021/api/v1/metrics"

current_feed_count_9999 = 0

feed_9999_status = "DOWN"

app = Flask(__name__)
t = None
job_timer = None

def check_feed():
    global current_feed_count_9999
    global feed_9999_status

    response = requests.get(feed_metrics_url_9999)
    if response.status_code == 200:
        response_json = json.loads(response.content)
        input_record_count=response_json['input']['tcp.0']['records']
        print("input records count: ",input_record_count)
        current_feed_count_9999 = int(requests.get("http://localhost:59999/get_feed_count_9999").content)
        print("current_feed_count_9999=",current_feed_count_9999)
        if input_record_count > current_feed_count_9999:
            feed_9999_status="UP"
        else:
            feed_9999_status="DOWN"
        requests.get("http://localhost:59999/set_feed_count_9999/"+str(input_record_count))
    else:
        print("fluent-bit tcp endpoint unavailable")
        feed_9999_status="DOWN"
    print("feed_9999_status: ",feed_9999_status)
    response = requests.get("http://localhost:59999//set_feed_status/"+feed_9999_status)

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

@app.route('/set_feed_count_9999/<string:count>')
def set_feed_count_9998(count):
    global current_feed_count_9999
    current_feed_count_9999=count
    return current_feed_count_9999

@app.route('/get_feed_count_9999')
def get_feed_count_9999():
    global current_feed_count_9999
    return str(current_feed_count_9999)

@app.route('/set_feed_status/<string:status>')
def set_feed_status(status):
    global feed_9999_status
    feed_9999_status = status
    return feed_9999_status

if __name__ == '__main__':
    nsec=10
    schedule.every(nsec).seconds.do(run_job, str(uuid.uuid4()))
    t = Process(target=run_schedule)
    t.start()
    app.run(host='0.0.0.0', port=59999)