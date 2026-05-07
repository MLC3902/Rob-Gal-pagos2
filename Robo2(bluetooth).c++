#include "BluetoothSerial.h" //Biblioteca para conexões bluetooth
BluetoothSerial SerialBT; //Registrand variável de bluetooth
char comando;


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

analogWrite(ENA,200); // Velocidade
analogWrite(ENB, 200); //Velocidade 

SerialBT.begin("Yangtzé"); //Nome do dispositivo

delay(1000); // Calma cocada espara 1 segundo

}

void loop() //Ordem do robõ
{
   if(SerialBT.available()) //Veja de recebeu algum comando
   {
    comando = SerialBT.read(); //Leia o comando recebido (similar ao scanf)

    //Sistema de if else para cada caracter recebido 

    if (comando == 'Y'){  //recebeu Y, o robõ vai pra frente
      robo_frente();
    }
    else if(comando == 'X'){ //recebeu X, o robõ vai pra direita
      robo_direita();
    }
    else if(comando == 'B'){ //recebeu B, o robõ vai pra esquerda
      robo_esquerda();
    }
    else if(comando == 'A'){ //recebeu A, o robõ vai pra trás
      robo_re();
    }
    else if(comando == 'M'){ //recebeu M, o robõ trava os motores
      robo_travado();
    }
    else if(comando == 'S'){ //recebeu S, o robõ parou
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










