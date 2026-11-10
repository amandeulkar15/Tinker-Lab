int pot = A0;
int led = 9;
int potValue = 0;
int brightness = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  potValue = analogRead(pot); 
  
  brightness = map(potValue, 0, 1023, 0, 255); 
  
  analogWrite(led, brightness); 
}
