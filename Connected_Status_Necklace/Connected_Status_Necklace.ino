#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "UW MPSK";            // Replace with your Wi-Fi name
const char* password = "***";    // Replace with your Wi-Fi password


WebServer server(80); // Start HTTP server on port 80

const int redPin = 13;
const int greenPin = 12;
const int bluePin = 14;

void setup() {
  Serial.begin(115200);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());  // This is the IP you'll use in your Shortcut

  // When Instagram is opened, trigger this endpoint
  server.on("/instagram", []() {
    Serial.println("Instagram opened!");
    blinkLED(); // Blink the LED or RGB light
    server.send(200, "text/plain", "Instagram open signal received");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

// Blink function
void blinkLED() {
  for (int i = 0; i < 5; i++) {
    setColor(255, 0, 0);  // Red
    delay(300);
    setColor(0, 0, 0);    // Off
    delay(300);
  }
  setColor(0, 255, 0);    // Set to green after blinking
}

// RGB control
void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}