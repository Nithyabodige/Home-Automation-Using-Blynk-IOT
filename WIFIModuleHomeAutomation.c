#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk Auth Token and WiFi credentials
char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

// Relay pins
#define relay1 D1
#define relay2 D2

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);  // OFF
  digitalWrite(relay2, HIGH);  // OFF
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0) {
  int state = param.asInt();
  digitalWrite(relay1, !state);  // Active LOW
}

BLYNK_WRITE(V1) {
  int state = param.asInt();
  digitalWrite(relay2, !state);  // Active LOW
}
