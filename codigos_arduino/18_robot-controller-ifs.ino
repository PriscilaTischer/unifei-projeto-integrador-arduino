#define p2m2 8
#define p1m2 7
#define pvelm2 6
#define p2m1 5
#define p1m1 4
#define pvelm1 3

int vel;

void setup() {
  vel = 200;
  Serial.begin(9600);
  pinMode(p1m1, OUTPUT);
  pinMode(p2m1, OUTPUT);
  pinMode(pvelm1, OUTPUT);
  pinMode(p1m2, OUTPUT);
  pinMode(p2m2, OUTPUT);
  pinMode(pvelm2, OUTPUT);
}

void irFrente(int v) {
  digitalWrite(p1m1, HIGH); digitalWrite(p2m1, LOW); analogWrite(pvelm1, v);
  digitalWrite(p1m2, HIGH); digitalWrite(p2m2, LOW); analogWrite(pvelm2, v);
}

void parar() {
  digitalWrite(p1m1, LOW); digitalWrite(p2m1, LOW); analogWrite(pvelm1, 0);
  digitalWrite(p1m2, LOW); digitalWrite(p2m2, LOW); analogWrite(pvelm2, 0);
}


void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.print("sinal: ");
    Serial.println(c);

    if (c == 'F') {
      Serial.println("Frente");
      irFrente(vel);
      delay(1000);
      parar();
    }
      }
}
