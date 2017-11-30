#include <ESP8266WiFi.h>
#include <PubSubClient.h> 
#include "Config.h"

#define DEBUG
 
WiFiClient espClient;
PubSubClient client(espClient);
char buf[50];

String reciveData = ""; 
char* reciveDataByte = "";

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
#endif
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {

  delay(10);
#ifdef DEBUG  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
#endif
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
#ifdef DEBUG
    Serial.print(".");
#endif
  }
#ifdef DEBUG
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
#endif
}

void callback(char* topic, byte* payload, unsigned int length) {
#ifdef DEBUG
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  Serial.print((char)payload[0] );
#endif  
#ifndef DEBUG
  Serial.begin(9600);
  while (Serial.available() == 0){
  }

  char a = Serial.readBytesUntil('\n', buf, 35);
  reciveData = buf;
  Serial.end();

  reciveData.toCharArray(reciveDataByte, 35);
  client.publish(publishTopic, reciveDataByte);
#endif 
}

void reconnect() {
  while (!client.connected()) {
#ifdef DEBUG    
    Serial.print("Attempting MQTT connection...");
#endif
    if (client.connect("ESP8266Client")) {
#ifdef DEBUG      
      Serial.println("connected");
#endif      
      client.publish("outTopic", "test");
      client.subscribe("inTopic");
    } else {
#ifdef DEBUG      
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
#endif      
      delay(5000);
    }
  }
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
}