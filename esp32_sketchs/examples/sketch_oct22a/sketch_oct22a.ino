// C++
// Function to read distance from HC-SR04 ultrasonic sensor
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  // LEDs pins: green, yellow, red
  pinMode(4, OUTPUT);  // Green LED
  pinMode(7, OUTPUT);  // Yellow LED
  pinMode(8, OUTPUT);  // Red LED

  // Power indicator LEDs or other pins from original code removed for clarity
}

void loop() {
  // Read distance in microseconds and convert to cm
  long duration = readUltrasonicDistance(2, 3);
  float distanceCm = duration * 0.01723;  // Sound speed conversion factor

  // Green LED: distance > 30 cm (normal level)
  if (distanceCm > 30) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }

  // Yellow LED: distance between 15 cm and 30 cm (medium alert)
  if (distanceCm > 15 && distanceCm <= 30) {
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }

  // Red LED: distance <= 15 cm (high alert)
  if (distanceCm <= 15) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(100);  // Small delay for stability
}