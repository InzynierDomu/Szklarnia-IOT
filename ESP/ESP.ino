/**
 * @file ESP.ino
 * @brief GreenHouse IOT - ESP
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#include <ESP8266WiFi.h>
#include <PubSubClient.h> 
#include "Config.h"

//#define DEBUG
 
WiFiClient espClient;             ///< ESP client for WIFI
PubSubClient client(espClient);   ///< connect MQTT on configuration WIFI

char buf[50];               ///< buffer for recived serial message 
String reciveData = "";     ///< recived MQTT message 
char* reciveDataByte = "";  ///< recived serial message 

/**
 * @brief preparation to work, startup
 */
void setup() 
{
#ifdef DEBUG
  Serial.begin(115200);
#endif
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

/**
 * @brief preparation WIFI communication
 */
void setup_wifi() 
{
  delay(10);
#ifdef DEBUG  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
#endif
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
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

/**
 * @brief callback for recived message by MQTT
 * @param topic: MQTT subscribed topic  
 * @param payload: MQTT message 
 * @param length: length MQTT message
 */
void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.begin(9600);
#ifdef DEBUG
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) 
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
#endif 
  Serial.print((char)payload[0] );
   
  while (Serial.available() == 0){}

  char a = Serial.readBytesUntil('\n', buf, 35);
  reciveData = buf;
  Serial.end();
  reciveData.toCharArray(reciveDataByte, 35);
  client.publish(publishTopic, reciveDataByte);
#ifndef DEBUG
  Serial.print("send response");
#endif 
}

/**
 * @brief connect to MQTT
 */
void reconnect() 
{
  while (!client.connected()) 
  {
#ifdef DEBUG    
    Serial.print("Attempting MQTT connection...");
#endif
    if (client.connect("ESP8266Client"))
    {
#ifdef DEBUG      
      Serial.println("connected");
#endif      
      client.publish("outTopic", "test");
      client.subscribe(subscribeTopic);
    } 
    else
    {
#ifdef DEBUG      
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
#endif      
      delay(5000);
    }
  }
}

/**
 * @brief main loop
 */
void loop() 
{
  if (!client.connected()) 
  {
    reconnect();
  }
  client.loop();
}
