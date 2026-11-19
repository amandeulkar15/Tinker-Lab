#include <LiquidCrystal.h>


int BuzzerPin = 10, LedRed = 12, WaterPump = 13;
int LedGreen = 11, SoilMoistureSensor = A0;


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


void setup() {
pinMode(WaterPump, OUTPUT);
pinMode(LedRed, OUTPUT);
pinMode(LedGreen, OUTPUT);
pinMode(BuzzerPin, OUTPUT);


Serial.begin(9600);
lcd.begin(16, 2);

pinMode(BuzzerPin, OUTPUT);

lcd.clear();
lcd.setCursor(0, 0);

String message1 = "Automated Plant";
String message2 = "Watering System";

for (int i = 0; i < message1.length(); i++) {
lcd.print(message1.charAt(i));
delay(100);
}

lcd.setCursor(0, 1);

for (int i = 0; i < message2.length(); i++) {
lcd.print(message2.charAt(i));
delay(100);
}

delay(2500);
lcd.clear();

lcd.setCursor(0, 0);
lcd.print("Moisture =");

lcd.setCursor(0, 1);
lcd.print("Water Pump =");
}

void loop() {
int Sensor = analogRead(SoilMoistureSensor);
int mappedValue = map(Sensor, 0, 876, 0, 99);

lcd.setCursor(11, 0);
lcd.print(mappedValue);

lcd.setCursor(14, 0);
lcd.print("%");

lcd.setCursor(13, 1);

if (mappedValue < 50) {
digitalWrite(WaterPump, HIGH);
digitalWrite(LedGreen, HIGH);
digitalWrite(LedRed, LOW);

lcd.print("ON ");
playSound();
}
else {
digitalWrite(WaterPump, LOW);
digitalWrite(LedGreen, LOW);
digitalWrite(LedRed, HIGH);

lcd.print("OFF");
	}
}

void playSound() {
tone(BuzzerPin, 87, 100);
delay(1000);
}