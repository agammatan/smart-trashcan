#include <Servo.h>
Servo serv; 
const int EchoPin = 8; //feel the back-wave from the trig 
const int TrigPin = 7; //trigers the chip to work
int Direc;

long microsecondsToCentimeters(long microseconds) {
  return microseconds/29/2;
}

void setup() {
  Serial.begin(9600);
  serv.attach(9);
  serv.write(90);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(3, OUTPUT);

}

void loop() {
  long duration, cm;
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  Serial.print("cm:");
  Serial.println(cm);

  if (cm < 10) {
    digitalWrite(3, HIGH);
    serv.write(180);
    delay(1000);
    serv.write(90);
    delay(1000);
    serv.write(90);
  }
  else  {
    digitalWrite(3, LOW);
  }
  delay(100);
}