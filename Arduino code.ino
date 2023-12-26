#include <Arduino.h>
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <WiFiClient.h>  //Client wifi connection library

#include <ThingSpeak.h>  //ThingSpeak Cloud library

#include "DHT.h"
#define DHTPIN D1     // what digital pin we're connected to
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define WIFI_SSID "yourWiFiSSID"
#define WIFI_PASSWORD "yourWiFiPassword"

WiFiClient client;  //client configuration

unsigned long myChannelNumber = channel_Number;  //Thingspeak channel number
const char * myWriteAPIKey = "API_key";  //Thingspeak Write API key

String readstring = "";

String level;

int ind1; // , locations

void setup()
{
  Serial.begin(9600);

  dht.begin();
 
  Serial.println();

  Serial.print("Connecting to AP");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(200);
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  ThingSpeak.begin(client);
}

void loop()
{
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" degC ");
  Serial.print(f);
  Serial.print(" degF\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" degC ");
  Serial.print(hif);
  Serial.println(" degF");
 
     
  ThingSpeak.setField(1, h);
  ThingSpeak.setField(2, t);
       
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);  
  delay(1000);
}
