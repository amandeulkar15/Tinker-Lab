int baselineTEMP = 0; 
int celsius = 0; 
int fahrenheit = 0; 

int Led_1 = 13; 
int Led_2 = 7; 
int Led_3 = 2; 
int buzzer = 8;

void setup(){ 
  pinMode(A0, INPUT); 
  Serial.begin(9600); 
  
  pinMode(Led_1, OUTPUT); 
  pinMode(Led_2, OUTPUT); 
  pinMode(Led_3, OUTPUT);
  pinMode(buzzer, OUTPUT);
} 

void loop(){ 
  baselineTEMP = 40; 
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); 
  fahrenheit = ((celsius * 9) / 5 + 32); 
  
  Serial.print(celsius); 
  Serial.print(" C, "); 
  Serial.print(fahrenheit); 
  Serial.println(" F"); 
  
  if(celsius < baselineTEMP){ 
    digitalWrite(Led_1, LOW); 
    digitalWrite(Led_2, LOW); 
    digitalWrite(Led_3, LOW);
    noTone(buzzer);
  } 
  else if(celsius >= baselineTEMP && celsius < baselineTEMP + 10){ 
    digitalWrite(Led_1, HIGH); 
    digitalWrite(Led_2, LOW); 
    digitalWrite(Led_3, LOW);
    noTone(buzzer);
  } 
  else if(celsius >= baselineTEMP + 10 && celsius < baselineTEMP + 20){ 
    digitalWrite(Led_1, HIGH); 
    digitalWrite(Led_2, HIGH); 
    digitalWrite(Led_3, LOW);
    noTone(buzzer);
  } 
  else if(celsius >= baselineTEMP + 20 && celsius < baselineTEMP + 30){ 
    digitalWrite(Led_1, HIGH); 
    digitalWrite(Led_2, HIGH); 
    digitalWrite(Led_3, HIGH);
    noTone(buzzer);
  } 
  else if(celsius >= baselineTEMP + 30){ 
    digitalWrite(Led_1, HIGH); 
    digitalWrite(Led_2, HIGH); 
    digitalWrite(Led_3, HIGH);
    tone(buzzer, 1250);
  } 
  
  delay(1000); 
}