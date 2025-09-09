#include <ESP8266WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>
#include <SinricProWebsocket.h>  // Include for ESP8266 websocket support

// SinricPro credentials
const char* APP_KEY = "f92be0bc-640b-4be3-a889-e45f40c0c46f";
const char* APP_SECRET = "731ed01b-415b-4a06-8e57-d5db802115c3-637b3b0d-b2aa-432f-9747-7abe9a552d41";

// Device IDs
const char* DEVICE_ID1 = "68a8566806eead9ae0332c69";
const char* DEVICE_ID2 = "68a8568f555f0cd05cf558ab";

// Use GPIO pins that don't interfere with serial communication
#define RELAY1_PIN 5  // D1 - GPIO5
#define RELAY2_PIN 4  // D2 - GPIO4

bool handlePowerState1(const String &deviceId, bool &state) {
  Serial.printf("Device %s turned %s\r\n", deviceId.c_str(), state ? "on" : "off");
  digitalWrite(RELAY1_PIN, state ? HIGH : LOW);
  return true;
}

bool handlePowerState2(const String &deviceId, bool &state) {
  Serial.printf("Device %s turned %s\r\n", deviceId.c_str(), state ? "on" : "off");
  digitalWrite(RELAY2_PIN, state ? HIGH : LOW);
  return true;
}

void setup() {
  Serial.begin(115200);

  // Set relay pins as output and initialize LOW
  pinMode(RELAY1_PIN, OUTPUT);
  digitalWrite(RELAY1_PIN, LOW);

  pinMode(RELAY2_PIN, OUTPUT);
  digitalWrite(RELAY2_PIN, LOW);

  // Connect to WiFi
  WiFi.begin("11111", "ani.16.ani");
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Register devices and callbacks
  SinricProSwitch& mySwitch1 = SinricPro[DEVICE_ID1];
  mySwitch1.onPowerState(handlePowerState1);

  SinricProSwitch& mySwitch2 = SinricPro[DEVICE_ID2];
  mySwitch2.onPowerState(handlePowerState2);

  // Start SinricPro
  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true);
}

void loop() {
  SinricPro.handle();
}