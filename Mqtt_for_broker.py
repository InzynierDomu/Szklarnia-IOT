#!/usr/bin/python

import time
import paho.mqtt.client as mqtt
import smtplib

def on_message(mqttc, obj, msg):	
	print 'Recive!'

client = mqtt.Client()
client.connect("127.0.0.1",1883,60)
client.subscribe("/greenHouse/recive",0)
client.on_message = on_message

client.loop_start()

while True:
   time.sleep(2)
