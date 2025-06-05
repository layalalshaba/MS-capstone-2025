#include <WiFi.h>
#include <WebSocketsServer.h>

#define BUTTON_PIN 27  // GPIO 27 with button to GND

char* ssid = "UW MPSK";  // Replace with your Wi-Fi
const char* password = "*****";

WebSocketsServer webSocket(81);  // WebSocket on port 81
bool playing = false;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.println("📡 Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ Wi-Fi connected!");
  Serial.print("🌐 ESP32 IP address: ");
  Serial.println(WiFi.localIP());

  webSocket.begin();
  webSocket.onEvent([](uint8_t num, WStype_t type, uint8_t* payload, size_t length) {
    // Not used in this setup — just required
  });

  Serial.println("🔌 WebSocket server started on port 81.");
}

void loop() {
  webSocket.loop();

  static bool buttonPressedLast = false;
  bool buttonNow = digitalRead(BUTTON_PIN) == LOW;

  if (buttonNow && !buttonPressedLast) {
    Serial.println("▶️ Button pressed — sending 'play'");
    webSocket.broadcastTXT("play");
  }

  buttonPressedLast = buttonNow;
}
