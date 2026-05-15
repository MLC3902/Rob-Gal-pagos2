#include "BluetoothSerial.h" //Biblioteca para conexões bluetooth
BluetoothSerial SerialBT; //Registrand variável de bluetooth
char comando;


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

pinMode(IN1,OUTPUT); 
pinMode(IN2,OUTPUT); 
pinMode(IN3,OUTPUT); 
pinMode(IN4,OUTPUT); 
pinMode(ENA1,OUTPUT); 
pinMode(ENB1,OUTPUT); 

pinMode(IN5,OUTPUT); 
pinMode(IN6,OUTPUT); 
pinMode(IN7,OUTPUT); 
pinMode(IN8,OUTPUT); 
pinMode(ENA2,OUTPUT); 
pinMode(ENB2,OUTPUT); 

analogWrite(ENA1,210); // Velocidade
analogWrite(ENB1, 210); //Velocidade 
analogWrite(ENA2,210); // Velocidade
analogWrite(ENB2, 210); //Velocidade 

SerialBT.begin("Yangtzé"); //Nome do dispositivo
delay(1000); // Calma cocada espara 1 segundo
}

void loop() 
{
   if(SerialBT.available()) //Veja de recebeu algum comando
   {
    comando = SerialBT.read(); //Leia o comando recebido (similar ao scanf)

    //Sistema de if else para cada caracter recebido 

    if (comando == 'Y'){  // Y frente
      robo_frente();
    }
    else if(comando == 'X'){ // X direita
      robo_direita();
    }
    else if(comando == 'B'){ // B esquerda
      robo_esquerda();
    }
    else if(comando == 'A'){ // A trás
      robo_re();
    }
    else if(comando == 'M'){ // M trava
      robo_travado();
    }
    else if(comando == 'S'){ // S para
      robo_parado();
    }
   }

   
}


void robo_frente()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
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
