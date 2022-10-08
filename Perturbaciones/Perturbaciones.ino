const unsigned int kp = 0;
unsigned int realim = 0;
bool input = false;

int error = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(3,OUTPUT);
  pinMode(8,INPUT);
  pinMode(A1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  input = digitalRead(8);
  realim = analogRead(A1);

  error = input - realim

  Serial.print("Valor de referencia: ");
  Serial.println(input);

  Serial.print("Valor de realimentacion: ");
  Serial.println(realim);
}
