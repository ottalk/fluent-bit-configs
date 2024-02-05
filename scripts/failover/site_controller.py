#!/usr/bin/python3

import requests
import json
import time
import os
import filecmp


# Get feed status from 9998,9999
# Check if peer feed_metrics_url_9998="http://localhost:2020/api/v1/metrics"
# monitor is available
# Determine if switch is required
# If so, coordinate switch between peers

site1_status = None
site2_status = None

site1="site1"
site2="site2"

site1_status_url='http://localhost:59998/get_feed_status'
site2_status_url='http://localhost:59999/get_feed_status'


config_dir='/home/ottalk/Github/fluent-bit-configs/etc/failover/'

def get_site_status(site):
    site_response = requests.get(site)
    if site_response.status_code == 200:
        site_status=site_response.text
    else:
        site_status="UNAVAILABLE"
    return site_status


def switch_site(source_site,target_site):
    os.popen('cp '+config_dir+source_site+'/tcp-null.conf '+config_dir+source_site+'/tcp-live.conf')
    time.sleep(2)
    if filecmp.cmp(config_dir+source_site+'/tcp-null.conf',config_dir+source_site+'/tcp-live.conf',shallow=False): 
        os.popen('cp '+config_dir+target_site+'/tcp-kafka.conf '+config_dir+target_site+'/tcp-live.conf')
        time.sleep(2)
        if filecmp.cmp(config_dir+target_site+'/tcp-kafka.conf',config_dir+target_site+'/tcp-live.conf',shallow=False):
            source_site_response = requests.put("http://localhost:2020/api/v2/reload")
            print("source_site_response:"+str(source_site_response.status_code))
            if source_site_response.status_code == 200:
                target_site_response = requests.put("http://localhost:2021/api/v2/reload")
                print("target_site_response:"+str(target_site_response.status_code))
                if target_site_response.status_code == 200:
                    return True
                else:
                    print("site2 reload failed")
                    return False
            else:
                print("site1 reload failed")
                return False
        else:
            print("site2 reconfig failed")
            return False
    else:
        print("site2 reconfig failed")
        return False

if __name__ == '__main__':

    print("INFO: defaulting to site1 at startup")
    curr_site="site1"

    site1_status=get_site_status(site1_status_url)
    site2_status=get_site_status(site2_status_url)
    print("curr_site: "+curr_site)
    print("site1: "+site1_status+" site2: "+site2_status)

    if switch_site(site2,site1):
        print("INFO: Switch to "+site1+ " successful")
        curr_site="site1"
    else:
        print("ERROR: Switch to "+site1+ " failed")
        exit(1)

    while True:
        site1_status=get_site_status(site1_status_url)
        site2_status=get_site_status(site2_status_url)
        print("curr_site: "+curr_site)
        print("site1: "+site1_status+" site2: "+site2_status)

        if (site1_status=="UP" and site2_status=="DOWN"):
            if (curr_site != "site1"):
                print("WARN: switching to site1")
                if switch_site(site2,site1):
                    print("INFO: Switch to "+site1+ " successful")
                    curr_site="site1"
                else:
                    print("ERROR: Switch to "+site1+ " failed")

        if (site1_status=="DOWN" and site2_status=="UP"):
            if (curr_site != "site2"):
                print("WARN: switching to site2")
                if switch_site(site1,site2):
                    print("INFO: Switch to "+site2+ " successful")
                    curr_site="site2"
                else:
                    print("ERROR: Switch to "+site2+ " failed")
        time.sleep(2)


    
