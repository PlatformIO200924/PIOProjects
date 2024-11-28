#include <Arduino.h>  // for arduino functions
#include <Wire.h>     // Wire lib for I2C communication

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();                            // init wire
  Serial.begin(115200);                    // start serial communication
  Serial.println("\nI2C Device scanner");  // print message
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) { return x + y; }