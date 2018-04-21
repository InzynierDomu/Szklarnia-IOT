#!/usr/bin/env python2.7

import socket
import paho.mqtt.client as mqtt
import MySQLdb as mdb
import sys

# dane do bazy danych
user = "newuser"
psw = "password"
db = "testDB"
tab = "mesurments"
host = "localhost"
#CREATE TABLE mesurments (id INT NOT NULL PRIMARY KEY AUTO_INCREMENT, Temperature INT, waterLvl INT, LightLvl INT, humidity INT, error INT, lightSts BOOL, pumpSts BOOL);

def on_connect(client, userdata, flags, rc):
    print("error = "+str(rc))

    client.subscribe("/greenHouse/recive")

def on_message(client, userdata, msg):
	print("message recive")
	print(msg.payload)
	measureTable = msg.payload.split(" ")
	AddRecord(measureTable)

def AddRecord(record):
        con = mdb.connect(host, user, psw, db);
        with con:
		cur = con.cursor()
		cur.execute("INSERT INTO %s VALUES(NULL,%s, %s, %s, %s, %s, %s, %s)" %(tab, record[1],record[2],record[3],record[4],record[5],record[6],record[7]))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect('127.0.0.1', 1883, 60)

client.loop_forever()
