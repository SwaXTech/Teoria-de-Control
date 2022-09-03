#include <DHT.h>

#define DHT_PIN 6
#define TIPO_DHT DHT11

DHT dht(DHT_PIN,TIPO_DHT);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
   
}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  Serial.println(t);
  delay(1000);
}
