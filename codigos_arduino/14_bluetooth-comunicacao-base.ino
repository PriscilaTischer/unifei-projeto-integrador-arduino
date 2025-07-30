#include <SoftwareSerial.h>

// Define os pinos RX e TX para a comunicação com o módulo Bluetooth
// Lembre-se: o RX do Arduino conecta no TX do módulo, e o TX do Arduino no RX do módulo.
SoftwareSerial BT(10, 11); // RX, TX

void setup() {
  // Inicia a comunicação com o computador (Monitor Serial)
  Serial.begin(9600);
  // Inicia a comunicação com o módulo Bluetooth
  BT.begin(9600);
  Serial.println("Pronto para receber comandos AT ou dados via Bluetooth.");
}

void loop() {
  // Se houver dados chegando do Bluetooth, envia para o computador
  if (BT.available()) {
    Serial.write(BT.read());
  }

  // Se houver dados chegando do computador, envia para o Bluetooth
  if (Serial.available()) {
    BT.write(Serial.read());
  }
}
