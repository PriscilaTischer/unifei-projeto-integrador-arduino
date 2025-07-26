int contador;

void setup() {
   Serial.begin(9600);
   contador = 0;
}

void loop() {
  if (contador > 10) {
    Serial.println("Seja Bem Vindo ao PI-2025 - 1");
    delay(2000);
    contador++;
  }
}
