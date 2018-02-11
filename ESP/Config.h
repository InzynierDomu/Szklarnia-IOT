/**
 * @file Config.h
 * @brief Conmfiguratino to comminiuaction ESP with WIFI and MQTT
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#define ssid  "wi fi"                               ///< Nazwa naszego Wi-Fi
#define password  "haslo"                           ///< Hasło Wi-Fi
#define mqtt_server  "192.168.0.169"                ///< ip raspberry pi lub innego serwera
#define subscribeTopic  "/greenHouse/cmd"           ///< topic do subskrypcji rozkazow
#define publishTopic  "/greenHouse/recive"          ///< topic do wysylania pomiarow
