#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int buttonPin = 7;
int ledPin = 8;

int buttonState = 0;
int lastButtonState = -1; 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); 
  
  lcd.begin(16, 2);
  
   lcd.print("System Ready");
  delay(1000); 
  lcd.clear();
  lcd.print("LED OFF"); 
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastButtonState) {
    lcd.clear();
    
    if (buttonState == HIGH) {
      digitalWrite(ledPin, HIGH);
      lcd.print("LED ON");
    } else {
      digitalWrite(ledPin, LOW);
      lcd.print("LED OFF");
    }
    
    lastButtonState = buttonState; 
  }
  
  delay(50); 
}