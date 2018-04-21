import paho.mqtt.client as mqtt

client = mqtt.Client()
client.connect("127.0.0.1")

client.publish("/greenHouse/cmd", "2" ,0)
