#include <Arduino.h>

// Define GPIO pins for the sound sensor and LEDs
const int soundSensorPin = 18;
const int led32Pin = 32;
const int led33Pin = 33;

// Threshold for sound intensity and delay time
const int threshold = 500;
const int delayTime = 5000; // 5 seconds in milliseconds

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(led32Pin, OUTPUT);
  pinMode(led33Pin, OUTPUT);
}

void loop() {
  // Read the analog value from the sound sensor
  int sensorValue = analogRead(soundSensorPin);

  // Check if the sensor value exceeds the threshold
  if (sensorValue > threshold) {
    // First clap detected
    delay(delayTime);

    // Check if a second clap was detected within the delay time
    if (analogRead(soundSensorPin) > threshold) {
      // Second clap detected
      digitalWrite(led33Pin, HIGH);
      delay(2000); // Keep LED 33 on for 2 seconds
      digitalWrite(led33Pin, LOW);
    } else {
      // No second clap detected
      digitalWrite(led32Pin, HIGH);
      delay(2000); // Keep LED 32 on for 2 seconds
      digitalWrite(led32Pin, LOW);
    }
  }
}
