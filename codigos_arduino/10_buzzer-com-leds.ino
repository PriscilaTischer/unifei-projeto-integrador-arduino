#define buzzer 10
#define g1 9
#define g2 8

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
}

void loop(){
  // Toca som e acende o primeiro LED
  tone(buzzer, 200);
  digitalWrite(g1, HIGH);
  digitalWrite(g2, LOW);
  delay(500);

  // Toca som e acende o segundo LED
  tone(buzzer, 400); // Mudei o tom para diferenciar
  digitalWrite(g2, HIGH);
  digitalWrite(g1, LOW);
  delay(500);
}
