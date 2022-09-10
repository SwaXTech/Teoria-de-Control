#include <DHT.h>
#include <math.h>

#define DHT_PIN 6
#define TIPO_DHT DHT11


DHT dht(DHT_PIN,TIPO_DHT);
float lastThresholdMeasured = 0;
float lastTempMeasured = 0;

float mapThresholdToCelsius(int threshold){
  return 0.09775171065 * threshold;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  dht.begin();
   
}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  if(t != lastTempMeasured){
    Serial.print("Temperature changed: ");
    Serial.print(t);
    Serial.println("°C");
    lastTempMeasured = t;  
  }

//  float measuredThreshold = analogRead(A0);
//  if(abs(measuredThreshold - lastThresholdMeasured) > 30 ){
//    Serial.print("Threshold changed: ");  
//    Serial.println(measuredThreshold);
//    lastThresholdMeasured = measuredThreshold;
//  }

   int measuredThreshold = analogRead(A0);
   float celsius = mapThresholdToCelsius(measuredThreshold);
   if(abs(celsius - lastThresholdMeasured) > 3){
      Serial.print("Threshold changed: ");  
      Serial.print(celsius);
      Serial.println("°C");
      lastThresholdMeasured = celsius;
   }
   
   if(lastTempMeasured < celsius){
     digitalWrite(8, HIGH);
   }
  
  delay(1000);
  digitalWrite(8, LOW);
}
