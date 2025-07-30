#define ledVermelho 7
#define ledAzul 6
#define farol 5
#define sirene 11

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(farol, OUTPUT);
  pinMode(sirene, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.print("Sinal recebido: ");
    Serial.println(c);

    // Desliga tudo antes de processar o novo comando
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(farol, LOW);
    noTone(sirene);

    // Liga o LED vermelho e a sirene
    if (c == 'A') {
      digitalWrite(ledVermelho, HIGH);
      tone(sirene, 440);
    }

    // Liga o LED azul
    if (c == 'a') {
      digitalWrite(ledAzul, HIGH);
    }

    // Liga o farol
    if (c == 'L') {
      digitalWrite(farol, HIGH);
    }
  }
}
