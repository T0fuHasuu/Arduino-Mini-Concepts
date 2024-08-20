#include <WiFi.h>
#include <time.h>

const char* ssid = "t0fu";
const char* password = "you@remyt0fu";

const int led1 = 26;
const int led2 = 25;
const int led3 = 32;
const int led4 = 33;

const long gmtOffset_sec = 7 * 3600;
const int daylightOffset_sec = 0;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Turn off all LEDs initially
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  WiFi.begin(ssid, password);
  int wifiTimeout = 10000;
  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < wifiTimeout) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi");
    initializeTime(true); // Use NTP to set time
  } else {
    Serial.println("\nWiFi not connected. Using RTC if available.");
    initializeTime(false); // Use RTC if NTP is not available
  }
}

void loop() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    delay(1000);
    return;
  }

  int currentHour = timeinfo.tm_hour;
  int currentMinute = timeinfo.tm_min;

  // Setting Alarm as 24 format
  if (currentHour == 0) {
    if (currentMinute == 28) {
      activateAlarm(led1);
    } else if (currentMinute == 29) {
      activateAlarm(led2);
    } else if (currentMinute == 30) {
      activateAlarm(led3);
    } else if (currentMinute == 31) { 
      activateAlarm(led4);
    }
  }
}

void activateAlarm(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(10000); //
  digitalWrite(ledPin, LOW);
}

void initializeTime(bool useNTP) {
  if (useNTP) {
    configTime(gmtOffset_sec, daylightOffset_sec, "pool.ntp.org");
    Serial.println("Time initialized from NTP.");
  } else {
    struct tm timeinfo;
    if (getLocalTime(&timeinfo) && timeinfo.tm_year > 70) {
      Serial.println("Using time from RTC.");
    } else {
      Serial.println("RTC not set. Please set the time manually or connect to WiFi.");
    }
  }
}