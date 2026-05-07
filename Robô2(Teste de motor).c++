
//Definido as portas q conectarão com os motores
#define IN1 26
#define IN2 27
#define IN3 17
#define IN4 16

#define ENA 25//Porta de velocidade do Motor 1
#define ENB 33//Porta de velocidade do Motor 2


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

robo_frente();
  
  delay(3000);

  robo_parado();

  delay(3000);

  robo_re();

  delay(3000);
  
  robo_esquerda();

  delay(3000);
  
  robo_parado();

  delay(3000);

  robo_direita();

}

void loop()
{

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










