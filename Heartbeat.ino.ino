#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Pins for the LCD (RS, E, D4, D5, D6, D7)

const int pulsePin = A0;  // Pulse sensor analog pin
const int ledPin = 13;    // Onboard LED pin

int threshold = 550;  // Adjust this threshold according to your environment

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD
  lcd.print("Pulse Rate:");
  lcd.setCursor(0, 1);
  lcd.print("Initializing");

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(pulsePin);
  int pulse = getHeartRate(sensorValue);

  lcd.setCursor(0, 1);
  lcd.print("                ");  // Clear the previous pulse rate
  lcd.setCursor(0, 1);
  lcd.print("Pulse: " + String(pulse) + " BPM");

  if (pulse > threshold) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED if pulse exceeds the threshold
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED if pulse is below the threshold
  }

  delay(1000);  // Delay for 1 second between readings
}

int getHeartRate(int sensorValue) {
  // Your pulse sensor code to calculate the heart rate goes here
  // This is just a placeholder, and you should replace it with your own logic
  // For a pulse sensor library, refer to the documentation of your specific sensor

  // Example placeholder code:
  int heartRate = map(sensorValue, 0, 1023, 60, 150);
  return heartRate;
}
