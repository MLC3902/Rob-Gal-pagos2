#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Nordic UART Service — o que o site usa para se conectar
#define SERVICE_UUID     "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHAR_UUID_RX     "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHAR_UUID_TX     "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

// === SUAS DEFINIÇÕES DE PINOS (sem mudança) ===
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33
#define IN5 19
#define IN6 18
#define IN7 5
#define IN8 17
#define ENA1 14
#define ENB1 32
#define ENA2 21
#define ENB2 16

BLECharacteristic *pTxChar;
bool connected = false;

// Protótipos (para o compilador não reclamar)
void robo_frente();
void robo_re();
void robo_esquerda();
void robo_direita();
void robo_parado();
void robo_travado();

class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *s)    { connected = true; }
  void onDisconnect(BLEServer *s) {
    connected = false;
    robo_parado();
    BLEDevice::startAdvertising(); // volta a anunciar para reconectar
  }
};

class RxCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *c) {
    std::string val = c->getValue();
    if (val.length() == 0) return;
    char cmd = val[0];

    if      (cmd == 'Y') robo_frente();
    else if (cmd == 'X') robo_direita();
    else if (cmd == 'B') robo_esquerda();
    else if (cmd == 'A') robo_re();
    else if (cmd == 'M') robo_travado();
    else if (cmd == 'S') robo_parado();
  }
};

void setup() {
  // Pinos (idêntico ao seu setup)
  int pins[] = {IN1,IN2,IN3,IN4,IN5,IN6,IN7,IN8,ENA1,ENB1,ENA2,ENB2};
  for (int p : pins) pinMode(p, OUTPUT);

  analogWrite(ENA1, 210); analogWrite(ENB1, 210);
  analogWrite(ENA2, 210); analogWrite(ENB2, 210);

  // Inicializa BLE
  BLEDevice::init("Yangtzé");
  BLEServer *server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());

  BLEService *service = server->createService(SERVICE_UUID);

  pTxChar = service->createCharacteristic(CHAR_UUID_TX,
    BLECharacteristic::PROPERTY_NOTIFY);
  pTxChar->addDescriptor(new BLE2902());

  BLECharacteristic *rxChar = service->createCharacteristic(CHAR_UUID_RX,
    BLECharacteristic::PROPERTY_WRITE |
    BLECharacteristic::PROPERTY_WRITE_NR);
  rxChar->setCallbacks(new RxCallbacks());

  service->start();
  BLEDevice::startAdvertising();
}

void loop() {
  delay(10);
}

// === SUAS FUNÇÕES DE MOVIMENTO (sem mudança) ===
void robo_frente() {
  digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
  digitalWrite(IN5,HIGH); digitalWrite(IN6,LOW);
  digitalWrite(IN7,HIGH); digitalWrite(IN8,LOW);
}
void robo_esquerda() {
  digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);  digitalWrite(IN4,HIGH);
  digitalWrite(IN5,HIGH); digitalWrite(IN6,LOW);
  digitalWrite(IN7,LOW);  digitalWrite(IN8,HIGH);
}
void robo_direita() {
  digitalWrite(IN1,LOW);  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
  digitalWrite(IN5,LOW);  digitalWrite(IN6,HIGH);
  digitalWrite(IN7,HIGH); digitalWrite(IN8,LOW);
}
void robo_parado() {
  digitalWrite(IN1,LOW); digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW); digitalWrite(IN4,LOW);
  digitalWrite(IN5,LOW); digitalWrite(IN6,LOW);
  digitalWrite(IN7,LOW); digitalWrite(IN8,LOW);
}
void robo_travado() {
  digitalWrite(IN1,HIGH); digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH); digitalWrite(IN4,HIGH);
  digitalWrite(IN5,HIGH); digitalWrite(IN6,HIGH);
  digitalWrite(IN7,HIGH); digitalWrite(IN8,HIGH);
}
void robo_re() {
  digitalWrite(IN1,LOW);  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);  digitalWrite(IN4,HIGH);
  digitalWrite(IN5,LOW);  digitalWrite(IN6,HIGH);
  digitalWrite(IN7,LOW);  digitalWrite(IN8,HIGH);
}
