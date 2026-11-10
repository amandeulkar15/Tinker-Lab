#include <Servo.h>

Servo myServo;
int pushb = 2;   
int servom = 9;  
int led = 13;    

void setup() {
  myServo.attach(servom);
  pinMode(pushb, INPUT); 
  pinMode(led, OUTPUT);
  myServo.write(0);
}

void loop() {
  int buttonState = digitalRead(pushb);

  if (buttonState == HIGH) {
    digitalWrite(led, HIGH);

    if (myServo.read() == 0) {
      myServo.write(90);
    } else {
      myServo.write(0);
    }
    delay(1000);
  } 
  
  else {
    digitalWrite(led, LOW);
  }
}
