#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT22   
SoftwareSerial mySerial(7, 6);
DHT dht(DHTPIN, DHTTYPE);
int gasSensor = A0; // select input pin for gasSensor
int val = 0; // variable to store the value coming from the sensor
void setup() {
  Serial.begin(9600);
  dht.begin();
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  val = analogRead(gasSensor); // read the value from the pot
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  if(mySerial.available()){ 
   mySerial.println(t);
   Serial.println("Done");
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  Serial.print("Air:");
  Serial.println( val );
  Serial.println("--------------------");
  
  
}
