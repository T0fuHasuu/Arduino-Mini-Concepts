// Pin definitions
const int digitalOutPin = 12;  // Digital Output pin from the sensor
const int analogOutPin = A0;   // Analog Output pin from the sensor (changed to A1)

// Initialize an LED pin if you want to use pin 13 for an indicator
const int ledPin13 = 13;       // Digital pin 13 for LED indicator

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the digital output pin and LED pin as INPUT and OUTPUT respectively
  pinMode(digitalOutPin, INPUT);
  pinMode(ledPin13, OUTPUT);
}

void loop() {
  // Read the digital output
  int digitalState = digitalRead(digitalOutPin);
  
  // Read the analog output from the specified analog pin
  int analogValue = analogRead(analogOutPin);

  // Print values to the Serial Monitor
  Serial.print("Digital Output: ");
  Serial.println(digitalState == HIGH ? "HIGH" : "LOW");
  Serial.print("Analog Output: ");
  Serial.println(analogValue);

  // Control the LED on pin 13 based on the light level
  if (digitalState == HIGH) {
    // Light level is above the threshold
    digitalWrite(ledPin13, HIGH); // Turn on the LED
  } else {
    // Light level is below the threshold
    digitalWrite(ledPin13, LOW); // Turn off the LED
  }

  // Small delay for stability
  delay(5000);
}
