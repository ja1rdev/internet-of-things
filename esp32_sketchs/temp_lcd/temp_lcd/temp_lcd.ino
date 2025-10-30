#include <LiquidCrystal.h>

// LCD wiring: RS=12, E=11, D4=5, D5=4, D6=3, D7=2
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Pins
const int sensorPin = A0;   // TMP36 analog output
const int ledPin    = 13;   // Red LED
const int motorPin  = 10;   // DC motor via transistor

void setup() {
  lcd_1.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);

  lcd_1.setCursor(0, 0);
  lcd_1.print("Monitoreando...");
  delay(2000);
  lcd_1.clear();
}

void loop() {
  // Read TMP36 and convert to Celsius
  int   sensorValue  = analogRead(sensorPin);         // 0..1023
  float voltage      = sensorValue * (5.0 / 1023.0);  // 0..5V
  float temperatureC = (voltage - 0.5) * 100.0;       // °C

  // LCD: show temperature
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp: ");
  lcd_1.print(temperatureC); 
  lcd_1.print(" C   ");

  // Control logic
  if (temperatureC <= 10) {
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, HIGH); delay(500);
    digitalWrite(ledPin, LOW);  delay(500);
  }
  else if (temperatureC >= 11 && temperatureC < 25) {
    digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
    delay(1000);
  }
  else if (temperatureC >= 26) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(motorPin, HIGH);
    delay(1000);
  }
}
