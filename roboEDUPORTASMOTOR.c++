//Definido as portas q conectarão com os motores
#define IN1 27 // Esquerda Frente
#define IN2 26 // Esquerda Trás
#define IN3 25 // Direita Frente
#define IN4 33 // Direita Trás

#define ENA 14//Porta de velocidade do Motor 1
#define ENB 32//Porta de velocidade do Motor 2


void initMotors(){

pinMode(IN1,OUTPUT); // Saída para motor 1
pinMode(IN2,OUTPUT); // Saída para motor 1
pinMode(IN3,OUTPUT); // Saída para motor 2
pinMode(IN4,OUTPUT); // Saída para motor 2
pinMode(ENA,OUTPUT); // velocidade para motor 1
pinMode(ENB,OUTPUT); // velocidade para motor 2

digitalWrite(ENA,HIGH);
digitalWrite(ENB,HIGH);


delay(1000); // Calma cocada espara 1 segundo

}

void stopMotors(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void robo_frente()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  }


void robo_esquerda()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void robo_direita()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void robo_parado()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void robo_travado()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);
}

void robo_re()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void egcDriver(float drive, float turn){

  float leftPower = drive - turn;
  float rightPower = drive + turn;
  
  leftPower = constrain(leftPower, -255, 255);
  rightPower = constrain(rightPower, -255, 255);
  
  if (leftPower > .1){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else if (leftPower < -.1){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    leftPower = 0;
  }
  
  if (rightPower > .1){
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else if (rightPower < -.1){
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    rightPower = 0;
  }
  
  analogWrite(ENA, abs(leftPower));
  analogWrite(ENB, abs(rightPower));
}//Definido as portas q conectarão com os motores
#define IN1 27 // Esquerda Frente
#define IN2 26 // Esquerda Trás
#define IN3 25 // Direita Frente
#define IN4 33 // Direita Trás

#define ENA 14//Porta de velocidade do Motor 1
#define ENB 32//Porta de velocidade do Motor 2


void initMotors(){

pinMode(IN1,OUTPUT); // Saída para motor 1
pinMode(IN2,OUTPUT); // Saída para motor 1
pinMode(IN3,OUTPUT); // Saída para motor 2
pinMode(IN4,OUTPUT); // Saída para motor 2
pinMode(ENA,OUTPUT); // velocidade para motor 1
pinMode(ENB,OUTPUT); // velocidade para motor 2

digitalWrite(ENA,HIGH);
digitalWrite(ENB,HIGH);


delay(1000); // Calma cocada espara 1 segundo

}

void stopMotors(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void robo_frente()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  }


void robo_esquerda()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void robo_direita()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void robo_parado()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void robo_travado()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);
}

void robo_re()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void egcDriver(float drive, float turn){

  float leftPower = drive - turn;
  float rightPower = drive + turn;
  
  leftPower = constrain(leftPower, -255, 255);
  rightPower = constrain(rightPower, -255, 255);
  
  if (leftPower > .1){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else if (leftPower < -.1){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    leftPower = 0;
  }
  
  if (rightPower > .1){
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else if (rightPower < -.1){
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    rightPower = 0;
  }
  
  analogWrite(ENA, abs(leftPower));
  analogWrite(ENB, abs(rightPower));
}
