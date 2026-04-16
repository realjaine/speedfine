#include <WiFi.h>
#include "config.h"
#include "twilio_handler.h"

#define SENSOR1 14
#define SENSOR2 27
#define BUZZER 26

long startTime, endTime;
float distance = 25.0;

void setup() {
  Serial.begin(115200);

  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(BUZZER, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
}

void loop() {

  if (digitalRead(SENSOR1) == LOW) {
    startTime = millis();

    while (digitalRead(SENSOR2) != LOW);

    endTime = millis();

    float timeSec = (endTime - startTime) / 1000.0;
    float speed = distance / timeSec;

    Serial.print("Speed: ");
    Serial.println(speed);

    if (speed > 50 && speed <= 100) {
      digitalWrite(BUZZER, HIGH);
      delay(300);
      digitalWrite(BUZZER, LOW);

      sendSMS("Overspeed detected! Fine: Rs.500");
    }

    if (speed > 100) {
      digitalWrite(BUZZER, HIGH);
      delay(500);
      digitalWrite(BUZZER, LOW);

      sendSMS("Severe overspeed! Fine: Rs.1000");
      makeCall();
    }

    delay(1000);
  }
}
