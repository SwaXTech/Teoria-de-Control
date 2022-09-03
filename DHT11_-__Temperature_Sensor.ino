#include <DHT.h>
#include <math.h>

#define DHT_PIN 6
#define TIPO_DHT DHT11


DHT dht(DHT_PIN,TIPO_DHT);
int lastThresholdMeasured = 0;
float lastTempMeasured = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
   
}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  if(t != lastTempMeasured){
    Serial.print("Temperature changed: ");
    Serial.println(t);
    lastTempMeasured = t;  
  }

  float measuredThreshold = analogRead(A0);
  if(abs(measuredThreshold - lastThresholdMeasured) > 30 ){
    Serial.print("Threshold changed: ");  
    Serial.println(measuredThreshold);
  }
  
  
  delay(1000);
}
