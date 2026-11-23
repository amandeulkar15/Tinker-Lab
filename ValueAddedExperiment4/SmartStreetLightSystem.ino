#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 8, 7, 6, 5, 4);

int ldr = A0;
int led1 = 9;
int led2 = 10;
int led3 = 11;

void setup() {
  lcd.begin(16, 2);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
  
  lcd.print("Smart Street");
  lcd.setCursor(0, 1);
  lcd.print("Light System");
  delay(2000);
  lcd.clear();
}

void loop() {

  int threshold = 500;
  int ldr_read = analogRead(ldr);

  Serial.println(ldr_read);

  lcd.setCursor(0, 0);
  lcd.print("Light: ");
  lcd.print(ldr_read);
  lcd.print("     ");
  lcd.setCursor(0, 1);

  if (ldr_read >= threshold) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    lcd.print("Lights: OFF    ");
  }

  else if (ldr_read >= threshold - 50) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    lcd.print("Lights: 1 ON   ");
  }

  else if (ldr_read >= threshold - 100) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    lcd.print("Lights: 2 ON   ");
  }

  else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    lcd.print("Lights: 3 ON   ");
  }

  delay(500);
}