#include <DHT.h>

#define DHTPIN 2      // Pino onde o sensor DHT está conectado
#define DHTTYPE DHT11 // Tipo do sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Espera 2 segundos entre as leituras
  delay(2000);

  // Lê a umidade e a temperatura
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Imprime os valores no monitor serial
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print("% | Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");
}
