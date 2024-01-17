#!/usr/bin/python3

import requests
import json

url="http://localhost:2020/api/v1/metrics"

response = requests.get(url)
response_json = json.loads(response.content)

input_record_count=response_json['input']['tcp.0']['records']

print(input_record_count)