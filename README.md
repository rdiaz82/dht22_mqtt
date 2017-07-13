# ESP8266 temperature / humidity transmitter over MQTT 
 this repository contains a simple DHT22 temperature and humidity transmitter over MQTT.

 ## Considerations
 This project has been developed using PlatformIO. In order to run project a private_settings.h should be provided inside src folder. The private_setting has the following structure:

 ````
const char* ssid = "Wifi_SSID";
const char* password = "Wifi_password";
const char* mqtt_server = "MQTT host";
const char* clientID = "MQTT client ID";
const char* temperatureTopic = "topic/for/temperature";
const char* humidityTopic = "topic/for/humidity";
const char * token ="MQTT token String";
const int32 refreshTime = 300000; //Time to refresh in seconds
 ````
 
I promise to publish more information about the wiring in the next few days :)