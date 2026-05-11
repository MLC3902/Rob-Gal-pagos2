#include "BluetoothSerial.h" //Biblioteca para conexões bluetooth
BluetoothSerial SerialBT; //Registrand variável de bluetooth
char comando;


//Definido portas q conectarão com os motores
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33

#define ENA 14
#define ENB 32


void setup(){

pinMode(IN1,OUTPUT); 
pinMode(IN2,OUTPUT); 
pinMode(IN3,OUTPUT); 
pinMode(IN4,OUTPUT); 
pinMode(ENA,OUTPUT); 
pinMode(ENB,OUTPUT); 

analogWrite(ENA,200); // Velocidade
analogWrite(ENB, 200); //Velocidade 

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










