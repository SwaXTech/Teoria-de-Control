#define LED_PIN 3

const unsigned int kp = 1;
unsigned int realim = 0;
bool input = false;
int input_fix = 0;
int response = 0;

int error = 0;

void ajustar_valor_referencia();

void ajustar_valor_referencia()
{
  if(input == true)
    input_fix = 1023;
  else
    input_fix = 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(LED_PIN,OUTPUT);
  pinMode(8,INPUT);
  pinMode(A2,INPUT);

  input = digitalRead(8);
  ajustar_valor_referencia();
}

void loop() {
  // put your main code here, to run repeatedly:

  realim = analogRead(A2);                    

  error = input_fix - realim;
  response = kp * error;

  Serial.print("Valor de referencia: ");
  Serial.println(input);

  Serial.print("Valor de realimentacion: ");
  Serial.println(realim);

  Serial.print("Valor de error: ");
  Serial.println(error);  

  analogWrite(LED_PIN,response);
  Serial.print("Diferencia de potencial SALIDA: ");
  Serial.println((response / 1023.0)*5);  
  Serial.println(" ");
  delay(500);
}
