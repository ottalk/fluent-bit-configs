#!/usr/bin/python3

import socket
import sys
import json
import random
import time
from datetime import datetime,timedelta,timezone

HOST, PORT = "localhost", 9999

# Create a socket (SOCK_STREAM means a TCP socket)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # Connect to server and send data
    sock.connect((HOST, PORT))

    try:
        while True:
            # Generate random datetime within last hour
            end=datetime.now()
            start=end + timedelta(minutes=-60)
            random_date=end + (start - end) * random.random()
            random_date_compact=random_date.strftime("%Y%m%d%H%M%S")

            # Generate two random numbers of fixed length
            random_no_1=random.randrange(111111,999999,6)
            random_no_2=random.randrange(111111,999999,6)

            event = {"event_time": str(random_date_compact), "seq1": str(random_no_1), "seq2": str(random_no_2)} # a real dict.

            data = json.dumps(event)

            sock.sendall(bytes(data,encoding="utf-8"))
            time.sleep(1)
    except KeyboardInterrupt:
        print("Keyboard interrupted...")

    # Receive data from the server and shut down
    #received = sock.recv(1024)
    #received = received.decode("utf-8")

finally:
    sock.close()
    print("TCP socket closed")

#print("Sent:     {}".format(data))
#print("Received: {}".format(received))
