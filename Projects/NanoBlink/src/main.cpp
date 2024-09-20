// Program to demomstrate a pin state which drive the LED HIGH or LOW
// Reference : https://docs.arduino.cc/built-in-examples/digital/StateChangeDetection/ 

#include <Arduino.h>

// constants won't change
const int ledPin{3}; // pin attached to the LED 
const int buttonPin{4}; // pin attached to the bush button

// variable will change
int buttonCounter = 0; // number of button pressed
int buttonState = 0; // current state
int previousState = 0; // previous state

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  */

  // Read the push button input
  buttonState = digitalRead(buttonPin);
  if(buttonState != previousState)
  {
    //Serial.println("Previous" + previousState );
    // if the button has changed increment counter
    if(buttonState == HIGH)
    {
      Serial.println("HIGH");
      buttonCounter++;
      Serial.println("");
      //Serial.println(true);
      Serial.print("number of button bushed: ");
      Serial.println(buttonCounter);      
    }
    else
    {
      Serial.println("OFF");
    }
    // delay to avoid bouncing
    delay(50);
  }
  previousState = buttonState;

  // if(buttonCounter % 4 == 0)
  // {
  //   digitalWrite(ledPin, HIGH);
  // }
  // else
  // {
  //   digitalWrite(ledPin, LOW);
  // }

  // Check button state and set LED accordingly
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

// put function definitions here:
int myFunction(int x, int y) { return x + y; }