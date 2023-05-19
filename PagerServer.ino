#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "SSID";
const char* password = "PASS";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Hello from ESP8266!");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
