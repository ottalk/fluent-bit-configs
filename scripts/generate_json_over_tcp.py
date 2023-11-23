import socket
import sys
import json
from datetime import datetime
import time

HOST, PORT = "localhost", 9999

#m ='{"id": 2, "name": "abc"}'
#m = {"id": 2, "name": "abc"} # a real dict.

#data = json.dumps(m)

# Create a socket (SOCK_STREAM means a TCP socket)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # Connect to server and send data
    sock.connect((HOST, PORT))
    seq_no=1
    while(True):
        curr_datetime=datetime.now()
        curr_datetime_str = curr_datetime.strftime("%Y%m%d%H%M%S")
        event={"HOST_DATE_TIME": curr_datetime_str,"SEQ": seq_no}
        event_json=json.dumps(event)
        sock.sendall(bytes(event_json,encoding="utf-8"))
        seq_no=seq_no+1
        time.sleep(1)


    # Receive data from the server and shut down
    #received = sock.recv(1024)
    #received = received.decode("utf-8")

finally:
    sock.close()

print("Sent:     {}".format(data))
#print("Received: {}".format(received))