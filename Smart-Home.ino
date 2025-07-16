// Include necessary libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// Blynk authentication token
char auth[] = "Your_BLYNK_AUTH_TOKEN";

// Define relay pins
#define FAN_RELAY D1   // Fan Control
#define LIGHT_RELAY D2 // LED Light Control

// Sensor pins
#define LDR_PIN A0     // Light sensor (LDR)
#define TEMP_PIN A1    // Temperature sensor (e.g., LM35)

// Thresholds
const int lightThreshold = 500; // Adjust based on LDR calibration
const float tempThreshold = 30.0; // Adjust based on required fan activation temperature

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Blynk.begin(auth, ssid, password);
    
    pinMode(FAN_RELAY, OUTPUT);
    pinMode(LIGHT_RELAY, OUTPUT);
    
    digitalWrite(FAN_RELAY, HIGH);
    digitalWrite(LIGHT_RELAY, HIGH);
}

void loop() {
    Blynk.run();
    autoModeControl();
}

// Manual mode control via Blynk
BLYNK_WRITE(V1) {
    digitalWrite(LIGHT_RELAY, param.asInt());
}

BLYNK_WRITE(V2) {
    digitalWrite(FAN_RELAY, param.asInt());
}

// Auto mode control based on sensors
void autoModeControl() {
    int lightValue = analogRead(LDR_PIN);
    float tempValue = (analogRead(TEMP_PIN) * 3.3 / 1024.0) * 100; // Convert LM35 reading to Celsius

    // Light control based on LDR
    if (lightValue < lightThreshold) {
        digitalWrite(LIGHT_RELAY, LOW); // Turn ON light
    } else {
        digitalWrite(LIGHT_RELAY, HIGH); // Turn OFF light
    }

    // Fan control based on temperature
    if (tempValue > tempThreshold) {
        digitalWrite(FAN_RELAY, LOW); // Turn ON fan
    } else {
        digitalWrite(FAN_RELAY, HIGH); // Turn OFF fan
    }
}

