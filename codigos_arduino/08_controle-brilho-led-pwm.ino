#define an5 A5
#define led 11

void setup() {
  pinMode(an5, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(an5));
  int valor = analogRead(an5);
  int conversao = valor / 4;
  Serial.println(conversao);
  analogWrite(led, conversao);
}
