#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define ledBranco 13
#define ledAmarelo 8
#define ledVermelho 12
#define buzzer 10

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(ledBranco, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  float temperatura = dht.readTemperature();
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  if (temperatura < 28) {
    // Condição Normal: acende LED branco
    digitalWrite(ledBranco, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  } else if (temperatura >= 28 && temperatura < 30) {
    // Condição de Atenção: acende LED amarelo
    digitalWrite(ledBranco, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  } else {
    // Condição de Alerta: acende LED vermelho e toca o buzzer
    digitalWrite(ledBranco, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 440); // Toca um som de alerta
  }
}
