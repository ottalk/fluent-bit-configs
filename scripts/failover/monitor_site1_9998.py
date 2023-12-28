#!/usr/bin/python3

from flask import Flask
import flask_monitoringdashboard as dashboard

app = Flask(__name__)

@app.route('/')
def index():
    return 'Hello World!'

if __name__ == '__main__':
  app.run(debug=True)