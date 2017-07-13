#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <private_settings.h>

#define DHTTYPE DHT22
#define DHTPIN  2

DHT dht(DHTPIN, DHTTYPE, 11);

float humidity, temp_c;           

WiFiClient espClient;
PubSubClient client(espClient);
char msg[50];

void setup_wifi() {
  delay(3);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void gettemperature() {
  humidity = dht.readHumidity();
  temp_c = dht.readTemperature();
}

void reconnect() {
  while (!client.connected()) {
    if ( WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
      }
    }
    if ( !client.connect(clientID, token, NULL) ) {
      delay( 5000 );
    }
  }
}

void setup() {
  client.setServer(mqtt_server, 1883);
  dht.begin();
}

void loop() {
    reconnect();
    gettemperature();
    dtostrf(temp_c , 2, 2, msg);
    client.publish(temperatureTopic, msg, true);
    dtostrf(humidity , 2, 2, msg);
    client.publish(humidityTopic, msg, true);
    WiFi.disconnect();
    delay(refreshTime);

}
