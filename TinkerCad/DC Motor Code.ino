void setup(){
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop(){
  int a=digitalRead(5);
  if (a==0){
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(10);
  }
  else
  {
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(100);
  }
}