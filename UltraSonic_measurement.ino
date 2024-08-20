#define trigPin 12
#define echoPin 13

#define led26 26
#define led25 25
#define led32 32
#define led33 33

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set up LED pins as outputs
  pinMode(led26, OUTPUT);
  pinMode(led25, OUTPUT);
  pinMode(led32, OUTPUT);
  pinMode(led33, OUTPUT);

  // Initially turn off all LEDs
  digitalWrite(led26, LOW);
  digitalWrite(led25, LOW);
  digitalWrite(led32, LOW);
  digitalWrite(led33, LOW);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED control based on distance
  if (distance >= 1 && distance <= 100) {
    digitalWrite(led26, HIGH);
    digitalWrite(led25, LOW);
    digitalWrite(led32, LOW);
    digitalWrite(led33, LOW);
  } else if (distance >= 101 && distance <= 200) {
    digitalWrite(led26, LOW);
    digitalWrite(led25, HIGH);
    digitalWrite(led32, LOW);
    digitalWrite(led33, LOW);
  } else if (distance >= 201 && distance <= 300) {
    digitalWrite(led26, LOW);
    digitalWrite(led25, LOW);
    digitalWrite(led32, HIGH);
    digitalWrite(led33, LOW);
  } else {
    digitalWrite(led26, LOW);
    digitalWrite(led25, LOW);
    digitalWrite(led32, LOW);
    digitalWrite(led33, HIGH);
  }

  delay(500);
}
