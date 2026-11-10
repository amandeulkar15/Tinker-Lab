int ldr = A0;
int led1 = 13;
int led2 = 12;
int led3 = 8;
int led4 = 7;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop() {
  int threshold = 500;
  int ldr_read = analogRead(ldr);
  Serial.println(ldr_read);
  
  if (ldr_read >= threshold) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  } 
  else if (ldr_read < threshold && ldr_read >= (threshold - 50)) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  } 
  else if (ldr_read < (threshold - 50) && ldr_read >= (threshold - 100)) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  } 
  else if (ldr_read < (threshold - 100) && ldr_read >= (threshold - 150)) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  } 
  else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  
  delay(1000);
}
