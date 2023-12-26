#!/usr/bin/env python3

import socket
import sys
import json
from datetime import datetime, timedelta
import time
import random
from barnum import gen_data

HOST, PORT = "localhost", 9999

processor_list=["A","B","C","D","E"]

# Create a socket (SOCK_STREAM means a TCP socket)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

connected = True

# Connect to server and send data
sock.connect((HOST, PORT))

while(True):
    curr_datetime=datetime.now()
    est_datetime=curr_datetime - timedelta(hours=5)

    curr_datetime_str = curr_datetime.strftime("%Y%m%d%H%M%S")
    est_datetime_str = est_datetime.strftime("%Y%m%d%H%M%S")
         
    guid_1 = random.randint(11111, 99999)
    guid_2 = random.randint(11111, 99999)

    processor = random.choice(processor_list)

    company_name=gen_data.create_company_name()
    company_division_id=random.randint(11111, 11133)

    transaction_amount=random.randint(111, 9999)

    event={"HOST_DATE_TIME": curr_datetime_str,"TRANSACTION_DATETIME": est_datetime_str,"COMPANY_NAME":company_name,"COMPANY_DIVISION":company_division_id,"GUID_1": guid_1,"GUID_2": guid_2,"PROCESSOR": processor,"TRANSACTION_AMOUNT":transaction_amount}
    print(event)
    event_json=json.dumps(event)
    try:
        sock.sendall(bytes(event_json,encoding="utf-8"))
        time.sleep(1)
    except socket.error:
        # set connection status and recreate socket
        connected = False
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  
        print("connection lost... reconnecting")
        while not connected:
            # attempt to reconnect, otherwise sleep for 2 seconds
            try:
                sock.connect((HOST, PORT))
                connected = True
                print("re-connection successful")
            except socket.error:
                time.sleep(2)
    except Exception:
        print("Exception")           
    # Receive data from the server and shut down
    #received = sock.recv(1024)
    #received = received.decode("utf-8")

    #print("Sent:     {}".format(event_json))
#print("Received: {}".format(received))