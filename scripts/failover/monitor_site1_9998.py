#!/usr/bin/python3

import schedule
import time
import datetime
import uuid
import requests
import json

from flask import Flask, request
from multiprocessing import Process

url="http://localhost:2020/api/v1/metrics"

app = Flask(__name__)
t = None
job_timer = None

def run_job(id):
    """ sample job with parameter """
    global job_timer
    print("timer job id={}".format(id))
    print("timer: {:.4f}sec".format(time.time() - job_timer))
    job_timer = time.time()
    response = requests.get(url)
    response_json = json.loads(response.content)
    input_record_count=response_json['input']['tcp.0']['records']
    print("input records count: ",input_record_count)


def run_schedule():
    """ infinite loop for schedule """
    global job_timer
    job_timer = time.time()
    while 1:
        schedule.run_pending()
        time.sleep(1)

@app.route('/timer/<string:status>')
def mytimer(status, nsec=10):
    global t, job_timer
    if status=='on' and not t:
        schedule.every(nsec).seconds.do(run_job, str(uuid.uuid4()))
        t = Process(target=run_schedule)
        t.start()
        return "timer on with interval:{}sec\n".format(nsec)
    elif status=='off' and t:
        if t:
            t.terminate()
            t = None
            schedule.clear()
        return "timer off\n"
    return "timer status not changed\n"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)