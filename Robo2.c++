
#define IN1 26
#define IN2 27
#define IN3 14
#define IN4 12

// #define ENA 25
// #define ENB 33

char comando;
bool modoAutomatico = false; 

void setup() {
  // pinMode(ENA, OUTPUT);
  // pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    comando = Serial.read();
    
    SerialBT.write(comando);

    if (comando == 'F') andarFrente();
    if (comando == 'T') andarTras();
    if (comando == 'D') virarDireita();
    if (comando == 'E') virarEsquerda();
    if (comando == 'P') parar();

    
    if (comando == 'A') modoAutomatico = true;  
    if (comando == 'M') modoAutomatico = false;  
  }

 
  if (modoAutomatico) {
    andarFrente();
    delay(2000);

    parar();
    delay(1000);

    andarTras();
    delay(2000);

    parar();
    delay(1000);
  }
}

void andarFrente() {
  // analogWrite(ENA, 150);
  // analogWrite(ENB, 150);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void andarTras() {
  // analogWrite(ENA, 150);
  // analogWrite(ENB, 150);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void virarDireita() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void virarEsquerda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
