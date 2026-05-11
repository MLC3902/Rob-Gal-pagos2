
//Definido as portas q conectarão com os motores
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33

#define ENA 14//Porta de velocidade do Motor 1
#define ENB 32//Porta de velocidade do Motor 2


void setup(){

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

void loop()
{
robo_frente();
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
