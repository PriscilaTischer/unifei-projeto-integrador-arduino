#define led 7

void setup() {
  pinMode(led, OUTPUT);
  // Inicia a comunicação serial para receber dados do Bluetooth
  Serial.begin(9600);
}

void loop() {
  // Verifica se há algum dado disponível para leitura
  if (Serial.available()) {
    char c = Serial.read(); // Lê o caractere recebido

    Serial.print("Sinal recebido: ");
    Serial.println(c);

    // Se o caractere for 'A', acende o LED
    if (c == 'A') {
      digitalWrite(led, HIGH);
    }

    // Se o caractere for 'a', apaga o LED
    if (c == 'a') {
      digitalWrite(led, LOW);
    }
  }
}
