#include <HCSR04.h>
#define A 15
#define B 10

HCSR04 hc(2, 3);
float distance = 0; 
float inputSignal = 0;
float error = 0;
int timeI = 0, timeF = 0, deltaTime = 0;
float accError = 0;
const unsigned int ki = 2;

float propFunction(float x)
{
  return A*x + B;
}

float propInput(float x)
{
  return 0.0975 * x;
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,INPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  
  // put your main code here, to run repeatedly:
  distance = hc.dist();
  inputSignal = analogRead(A1);
  timeF = millis();

  Serial.print("Distancia: ");
  Serial.println(distance);
  Serial.print("Input: ");
  Serial.println(propInput(inputSignal));

  deltaTime = timeF - timeI; 

  error = inputSignal - distance;
  accError += error * deltaTime;

  analogWrite(9, propFunction(error) + ki * accError);
  
  timeI = millis();
}
