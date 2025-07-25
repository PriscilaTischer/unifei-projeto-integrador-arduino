nt tempo;

void setup() {
  pinMode (13, OUTPUT);
  tempo = 1000;
}

void loop() {
  digitalWrite(13, HIGH);
  delay(tempo);
  digitalWrite(13, LOW);
  delay(tempo);
  tempo = tempo + 1000;
}
