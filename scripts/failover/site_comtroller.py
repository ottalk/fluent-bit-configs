#!/usr/bin/python3

import requests
import json
import time
import os


# Get feed status from 9998,9999
# Check if peer feed_metrics_url_9998="http://localhost:2020/api/v1/metrics"
# monitor is available
# Determine if switch is required
# If so, coordinate switch between peers

site1_status = None
site2_status = None

def get_site_status(site):
    site_response = requests.get(site)
    if site_response.status_code == 200:
        site_status=site_response.text
    else:
        site_status="UNAVAILABLE"
    return site_status

def switch_to_site1():
    config_dir='/home/ottalk/Github/fluent-bit-configs/etc/failover/'
    os.popen('cp '+config_dir+'site1/tcp9998-kafka.conf '+config_dir+'site1/tcp9998-live.conf')
    os.popen('cp '+config_dir+'site2/tcp9999-null.conf '+config_dir+'site1/tcp9999-live.conf')
    return "switch successful"

def switch_to_site2():
    config_dir='/home/ottalk/Github/fluent-bit-configs/etc/failover/'
    os.popen('cp '+config_dir+'site1/tcp9998-null.conf '+config_dir+'site1/tcp9998-live.conf')
    os.popen('cp '+config_dir+'site2/tcp9999-kafka.conf '+config_dir+'site1/tcp9999-live.conf')
    return "switch successful"

if __name__ == '__main__':
    
    curr_site="site1"

    while True:
        site1='http://localhost:59998/get_feed_status'
        site2='http://localhost:59999/get_feed_status'
        site1_status=get_site_status(site1)
        site2_status=get_site_status(site2)
        print("site1: "+site1_status+" site2: "+site2_status)
        if (site1_status=="UP" and site2_status=="DOWN"):
            if (curr_site != "site1"):
                print("switching to site1")
                response=switch_to_site1()
                if (response=="switch successful"):
                    curr_site="site1"
        if (site1_status=="DOWN" and site2_status=="UP"):
            if (curr_site != "site2"):
                print("switching to site2")
                response=switch_to_site2()
                if (response=="switch successful"):
                    curr_site="site2"
        time.sleep(2)


    
