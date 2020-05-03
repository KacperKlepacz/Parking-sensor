#include <Wire.h> 

const int ledR = 2;
const int buzz = 3;
const int ledBlink = 4;
const int trig = 5;
const int echo = 6;
long czas;
int odl;  

void setup() {
pinMode(ledR,OUTPUT);
pinMode(ledBlink,OUTPUT);
pinMode(buzz,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
}

void loop() {
 
  digitalWrite(trig,HIGH);
  delay(2);
  digitalWrite(trig,LOW);
  czas = pulseIn(echo,HIGH);
  odl = czas/58;
  delay(10);
        
    if(odl <= 200 & odl > 70){
      tone(buzz,50);
      digitalWrite(ledR,HIGH);
      delay(100);
      digitalWrite(ledR,LOW);
      noTone(buzz);
      delay(400);
    }
    else if(odl <= 70 & odl >= 30){
      digitalWrite(ledBlink,LOW);
      tone(buzz,50);
      digitalWrite(ledR,HIGH);
      delay(50);
      noTone(buzz);
      digitalWrite(ledR,LOW);
      delay(50);
    }
    else if(odl < 30){
       tone(buzz,400);
       digitalWrite(ledR,LOW);
       digitalWrite(ledBlink,HIGH);
       delay(50);
    }

}
