#include <DHT.h>
#include <math.h>

#define DHT_PIN 6
#define TIPO_DHT DHT11

DHT dht(DHT_PIN, TIPO_DHT);
float lastThresholdMeasured = 0;
float referenceValue = 0;

float mapThresholdToCelsius(int threshold)
{
    return 0.09775171065 * threshold;
}

void printResult(String measured, float value, String unit, float realValue)
{
    Serial.print(measured);
    Serial.print(": ");
    Serial.print(value);
    Serial.print(unit);
    if(realValue != 0)
    {
      Serial.print(" - ");
      Serial.print("(");
      Serial.print(realValue);
      Serial.print(")");
    }
    Serial.println();
      
}

float mapErrorToFreq(float error)
{
  return 30 * error + 145;
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    dht.begin();
}

void loop()
{
    for (int i = 0; i < 10; i++)
    {
        Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    float t = dht.readTemperature();
    printResult("Temperature", t, "°C", 0);

    int measuredThreshold = analogRead(A0);
    float celsius = mapThresholdToCelsius(measuredThreshold);
    if (abs(celsius - lastThresholdMeasured) > 10)
    {
        printResult("Threshold", celsius, "°C", measuredThreshold);
        lastThresholdMeasured = celsius;
        referenceValue = celsius;
    }
    else
    {
        printResult("Threshold", lastThresholdMeasured, "°C", measuredThreshold);
    }

    // error = referencia mapeada a celsius - temp medida
    float error = t - referenceValue;

    printResult("Error", error, "°C", 0);

    referenceValue = referenceValue + error;
    printResult("Reference Value", referenceValue, "°C", 0);

    float freq = mapErrorToFreq(error);
    printResult("Frequency", freq, "", 0);
    analogWrite(8, freq);
    delay(1000);
}
