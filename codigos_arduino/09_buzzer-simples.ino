#define buzzer 10

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop(){
  tone(buzzer, 200); // Toca um som de 200Hz
  delay(1000);       // Deixa tocando por 1 segundo
  noTone(buzzer);    // Para o som
  delay(1000);       // Fica em silêncio por 1 segundo
}
