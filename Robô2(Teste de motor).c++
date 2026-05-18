
//PONTE1
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33

//PONTE2
#define IN5 19
#define IN6 18
#define IN7 5
#define IN8 17

#define ENA1 14//Porta de velocidade do Motor 1
#define ENB1 32//Porta de velocidade do Motor 1

#define ENA2 21//Porta de velocidade do Motor 2
#define ENB2 16//Porta de velocidade do Motor 2


void setup(){

pinMode(IN1,OUTPUT); // Saída para motor 1
pinMode(IN2,OUTPUT); // Saída para motor 1
pinMode(IN3,OUTPUT); // Saída para motor 1
pinMode(IN4,OUTPUT); // Saída para motor 1
pinMode(ENA1,OUTPUT); // velocidade para motor 1
pinMode(ENB1,OUTPUT); // velocidade para motor 1

digitalWrite(ENA1,HIGH);
digitalWrite(ENB1,HIGH);

pinMode(IN5,OUTPUT); // Saída para motor 1
pinMode(IN6,OUTPUT); // Saída para motor 1
pinMode(IN7,OUTPUT); // Saída para motor 1
pinMode(IN8,OUTPUT); // Saída para motor 1
pinMode(ENA2,OUTPUT); // velocidade para motor 1
pinMode(ENB2,OUTPUT); // velocidade para motor 1

digitalWrite(ENA2,HIGH);
digitalWrite(ENB2,HIGH);
digitalWrite(ENA1,HIGH);
digitalWrite(ENB1,HIGH);

delay(1000); // Calma cocada espara 1 segundo

}

void loop()
{
robo_frente();
}

void robo_frente()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

  digitalWrite(IN5,HIGH);
  digitalWrite(IN6,LOW);
  digitalWrite(IN7,HIGH);
  digitalWrite(IN8,LOW);
  }


void robo_esquerda()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

   digitalWrite(IN5,HIGH);
  digitalWrite(IN6,LOW);
  digitalWrite(IN7,LOW);
  digitalWrite(IN8,HIGH);
}

void robo_direita()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

   digitalWrite(IN5,LOW);
  digitalWrite(IN6,HIGH);
  digitalWrite(IN7,HIGH);
  digitalWrite(IN8,LOW);
}

void robo_parado()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

   digitalWrite(IN5,LOW);
  digitalWrite(IN6,LOW);
  digitalWrite(IN7,LOW);
  digitalWrite(IN8,LOW);
}

void robo_travado()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);

   digitalWrite(IN5,HIGH);
  digitalWrite(IN6,HIGH);
  digitalWrite(IN7,HIGH);
  digitalWrite(IN8,HIGH);
}

void robo_re()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

   digitalWrite(IN5,LOW);
  digitalWrite(IN6,HIGH);
  digitalWrite(IN7,LOW);
  digitalWrite(IN8,HIGH);
}
