#include <Arduino.h>

int ledpin =10;
int buttonONPin = 8;
int buttonOffPin = 9;

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);

  pinMode(ledpin, OUTPUT);
  pinMode(buttonONPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonONPin) == LOW)
  {
    digitalWrite(ledpin, HIGH);
  }

  if(digitalRead(buttonOffPin) == LOW)
  {
    digitalWrite(ledpin, LOW);
  }

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}