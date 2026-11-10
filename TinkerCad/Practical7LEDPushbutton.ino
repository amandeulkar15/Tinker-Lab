int LED = 13; 
int PB = 2; 

void setup() { 
  pinMode(PB, INPUT_PULLUP); 
  pinMode(LED, OUTPUT); 
} 

void loop() { 
  int state = digitalRead(PB); 
  
  if (state == LOW) {      
    digitalWrite(LED, HIGH);
  }                       
  else { 
    digitalWrite(LED, LOW);
  } 
}
