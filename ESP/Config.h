/**
 * @file Config.h
 * @brief Conmfiguratino to comminiuaction ESP with WIFI and MQTT
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#define ssid  "Nazwa_wifi"                      ///< personal Name WIFI
#define password  "haslo_do_wifi"               ///< personal password for WIFI
#define mqtt_server  "192.168.0.169"            ///< personal IP MQTT broker
#define subscribeTopic  "/greenHouse/recive"    ///< subscribe MQTT topic
#define publishTopic  "/greenHouse/cmd"         ///< MQTT topic to publishing
