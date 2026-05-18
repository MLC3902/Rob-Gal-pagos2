#include <WiFi.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include <WebSocketsServer_Generic.h>
#include <math.h>
#include <motors.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "Espizinho";
const char* password = "Luiza";

float gRightX = 0, gRightY = 0, gLeftX = 0, gLeftY = 0;
unsigned long lastMsgTime = 0;

WebSocketsServer webSocket = WebSocketsServer(81);

AsyncWebServer server(80);

const char htmlPage[] PROGMEM = R"rawliteral(

<!DOCTYPE html>
  <html lang="pt-br">
  <head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP Control</title>

  <style>
    body { text-align: center; font-family: Arial; background: #222; color: white; }
    section { display: flex; flex-flow: row no-wrap; justify-content: space-between; align-items: center; }
    
    .joystick { width: 200px; height: 200px; background: #444; border-radius: 50%; margin: auto; position: relative; touch-action: none;}
    .stick { width: 60px; height: 60px; background: #ff4444; border-radius: 50%; position: absolute; top: 70px; left: 70px; }

  </style>
  </head>
  <body>
  <h2>ESP32 WebSocket Joystick</h2>

  <section>
    <div class="joystick" id="lJoystick">
      <div class="stick" id="lStick"></div>
    </div>
    <p>left X: <span id="lXVal">0</span> | left Y: <span id="lYVal">0</span></p>

    <div class="joystick" id="rJoystick">
      <div class="stick" id="rStick"></div>
    </div>
    <p>right X: <span id="rXVal">0</span> | right Y: <span id="rYVal">0</span></p>
  </section>

  <script>
  let leftJoy = document.getElementById("lJoystick");
  let leftStick = document.getElementById("lStick");

  let rightJoy = document.getElementById("rJoystick");
  let rightStick = document.getElementById("rStick");

  let centerX = leftJoy.offsetWidth / 2;
  let centerY = leftJoy.offsetHeight / 2;
  let maxDist = centerX - leftStick.offsetWidth / 2;
  let lLastSend = 0;
  let rLastSend = 0;

  let ws = new WebSocket("ws://" + window.location.hostname + ":81/");

  leftJoy.addEventListener("touchmove", function(e) {
    e.preventDefault();
    let touch = e.touches[0];
    let rect = leftJoy.getBoundingClientRect();
    
    let x = touch.clientX - rect.left - centerX;
    let y = touch.clientY - rect.top - centerY;

    let dist = Math.sqrt(x*x + y*y);
    if (dist > maxDist) {
      x *= maxDist / dist;
      y *= maxDist / dist;
    }
    
    leftStick.style.transform = `translate(${x}px, ${y}px)`;
    
    let dX = x / maxDist;
    let dY = (y / maxDist) * -1;

    dX = Math.max(-1, Math.min(1, dX));
    dY = Math.max(-1, Math.min(1, dY));

    let Mg = Math.sqrt(dX*dX + dY*dY);
    if (Mg > 1) Mg = 1;

    if (Mg < 0.05) Mg = 0;

    Mg = Math.pow(Mg, 1.8);

    let angle = Math.atan2(dY, dX);

    let normX = Math.cos(angle) * Mg;
    let normY = Math.sin(angle) * Mg;

    document.getElementById("lXVal").innerText = normX.toFixed(2);
    document.getElementById("lYVal").innerText = normY.toFixed(2);
    if ((Date.now() - lLastSend > 50) && (ws.readyState === WebSocket.OPEN)) {
      ws.send("L," + normX.toFixed(2) + "," + normY.toFixed(2));
      lLastSend = Date.now();
    }
  }, false);

  leftJoy.addEventListener("touchend", function() {
    leftStick.style.transform = "translate(0px, 0px)";
    document.getElementById("lXVal").innerText = 0;
    document.getElementById("lYVal").innerText = 0;
    if (ws.readyState === WebSocket.OPEN){
      ws.send("L,0,0");
    }
  }, false);

  rightJoy.addEventListener("touchmove", function(e) {
    e.preventDefault();
    let touch = e.touches[0];
    let rect = rightJoy.getBoundingClientRect();
    
    let x = touch.clientX - rect.left - centerX;
    let y = touch.clientY - rect.top - centerY;
    let dist = Math.sqrt(x*x + y*y);
    if (dist > maxDist) {
      x *= maxDist / dist;
      y *= maxDist / dist;
    }
    rightStick.style.transform = `translate(${x}px, ${y}px)`;

    let dX = x / maxDist;
    let dY = (y / maxDist) * -1;

    dX = Math.max(-1, Math.min(1, dX));
    dY = Math.max(-1, Math.min(1, dY));

    let Mg = Math.sqrt(dX*dX + dY*dY);
    if (Mg > 1) Mg = 1;

    if (Mg < 0.05) Mg = 0;

    Mg = Math.pow(Mg, 1.8);

    let angle = Math.atan2(dY, dX);

    let normX = Math.cos(angle) * Mg;
    let normY = Math.sin(angle) * Mg;

    document.getElementById("rXVal").innerText = normX.toFixed(2);
    document.getElementById("rYVal").innerText = normY.toFixed(2);

    if ((Date.now() - rLastSend > 50) && (ws.readyState === WebSocket.OPEN)) {
      ws.send("R," + normX.toFixed(2) + "," + normY.toFixed(2));
      rLastSend = Date.now();
    }
  }, false);

  rightJoy.addEventListener("touchend", function() {
    rightStick.style.transform = "translate(0px, 0px)";

    document.getElementById("rXVal").innerText = 0;
    document.getElementById("rYVal").innerText = 0;
    if (ws.readyState === WebSocket.OPEN){
      ws.send("R,0,0");
    }
  }, false);

  </script>
  </body>
  </html>
)rawliteral";

void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  switch (type) {
    case WStype_CONNECTED:
      Serial.printf("Cliente [%u] conectado.\n", num);
      break;
    case WStype_DISCONNECTED:
      Serial.printf("Cliente [%u] desconectado.\n", num);
      gLeftX = gRightX = 0;
      gLeftY = gRightY = 0;
      stopMotors();
      break;
    case WStype_TEXT: {
      String data = (char*)payload;

      lastMsgTime = millis();

      if (data.length() < 3) return;

      char joystick = data.charAt(0); 

      int firstComma = data.indexOf(',');
      int secondComma = data.indexOf(',', firstComma + 1);

      if (firstComma == -1 || secondComma == -1) return;

      float x = data.substring(firstComma + 1, secondComma).toFloat();
      float y = data.substring(secondComma + 1).toFloat();

      if (joystick == 'L') {
        gLeftX = x;
        gLeftY = y;

        Serial.print("Left X: ");
        Serial.print(x);
        Serial.print(" | Left Y: ");
        Serial.println(y);

      } else if (joystick == 'R') {
        gRightX = x;
        gRightY = y;

        Serial.print("Right X: ");
        Serial.print(x);
        Serial.print(" | Right Y: ");
        Serial.println(y);
      }

      break;
    }
    default:
      break;
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Iniciando Access Point...");

  // WiFi.mode(WIFI_STA);

  if (!WiFi.softAP(ssid, password)) {
    Serial.println("Falha ao criar AP.");
    while (1);
  }

  Serial.print("IP do AP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request -> send_P(200, "text/html", htmlPage);
  });

  
  server.begin();

  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);

  Serial.println("Servidor iniciado");

  initMotors();
  
  lastMsgTime = millis();

  pinMode(2, OUTPUT);

}

void loop() {

  // WiFiClient client = server.available();

  // if (client) {
  //   String req = client.readStringUntil('\r');
  //   client.flush();
  //   if (req.indexOf("GET / ") >= 0) {
  //     client.println("HTTP/1.1 200 OK");
  //   client.println("Content-Type: text/html");
  //   client.println("Connection: close");
  //   client.println();
  //   client.print(htmlPage);
  //   } else {
  //     client.println("HTTP/1.1 404 Not Found\r\n\r\n");
  //   }
  //   delay(1);
  //   client.stop();
  // }

  webSocket.loop();

  // frontMove(gRightX);
  // lateMove(gRightX);

  egcDriver(gLeftY, gLeftX);

  if (millis() - lastMsgTime > 500){
    stopMotors();
  }

}
