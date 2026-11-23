#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensor = A0;
int buzzer = 8;

float voltage;
float temperature;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  lcd.print("Temp Monitor");
  delay(1500);
  lcd.clear();
}

void loop() {
  int reading = analogRead(sensor);

  voltage = reading * (5.0 / 1023.0);
  temperature = (voltage - 0.5) * 100;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print(" C   ");

  if (temperature > 30) {
    lcd.setCursor(0, 1);
    lcd.print("HIGH TEMP ALERT!");
    tone(buzzer, 1000);
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("Normal Temp     ");
    noTone(buzzer);
  }

  delay(1000);
}
