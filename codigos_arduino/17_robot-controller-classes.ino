#define p2m2 8
#define p1m2 7
#define pvelm2 6
#define p2m1 5
#define p1m1 4
#define pvelm1 3

class Motor {
  public:
    int p1, p2, pv;
    Motor(int p1_in, int p2_in, int pv_in) {
      p1 = p1_in;
      p2 = p2_in;
      pv = pv_in;
      pinMode(p1, OUTPUT);
      pinMode(p2, OUTPUT);
      pinMode(pv, OUTPUT);
    }
    void frente(int v) {
      digitalWrite(p1, HIGH);
      digitalWrite(p2, LOW);
      analogWrite(pv, v);
    }
    void tras(int v) {
      digitalWrite(p1, LOW);
      digitalWrite(p2, HIGH);
      analogWrite(pv, v);
    }
    void parar() {
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
      analogWrite(pv, 0);
    }
};

Motor md = Motor(p1m1, p2m1, pvelm1); // Motor da direita
Motor me = Motor(p1m2, p2m2, pvelm2); // Motor da esquerda
int vel = 200; // Velocidade padrão

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    switch (cmd) {
      case 'F':
        md.frente(vel);
        me.frente(vel);
        Serial.println("Frente");
        break;
          }
  }
}

