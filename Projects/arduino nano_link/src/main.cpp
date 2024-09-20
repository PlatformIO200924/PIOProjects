#include <Arduino.h>
int x = 2, y= 3;
// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  int result = myFunction(x, y);
  Serial.println("Hello Nano ");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);

  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}