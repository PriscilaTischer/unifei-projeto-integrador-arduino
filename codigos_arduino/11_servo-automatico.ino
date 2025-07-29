#include <Servo.h>

#define pservo 10

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(pservo);
  servo.write(90); // Inicia o servo no centro (90 graus)
}

void loop() {
  // Move para a esquerda
  servo.write(180);
  Serial.println("Esquerda.");
  delay(1000);

  // Volta para o centro
  servo.write(90);
  Serial.println("Centro.");
  delay(1000);

  // Move para a direita
  servo.write(0);
  Serial.println("Direita.");
  delay(1000);

  // Volta para o centro
  servo.write(90);
  Serial.println("Centro.");
  delay(1000);
}

