#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_LiquidCrystal.h>


// Variables 
#define DHTPIN 6 // connected to pin 2
#define DHTTYPE DHT11


DHT dht(DHTPIN, DHTTYPE); 
Adafruit_LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println(F("DHTxx test!"));
  Serial.println("DHT11 test PIO!");
  
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(1000); // Wait a few seconds between measurements
  // read temperature default(Celsius), can also read in Fahrenheit
  float temperature = dht.readTemperature();
  // Read Humidity reading
  float humidity = dht.readHumidity();


  // Check for errors 
  if(isnan(temperature)|| isnan(humidity))
  {
    Serial.println(F("Failded to read from DHT sensor!"));
    return;
  }

 // Print to serial
  Serial.print("Temp in C " );
  Serial.println(temperature);

  Serial.print("Hum in % " );
  Serial.println(humidity);
  
  
  

  // Print to Lcd
  lcd.begin(16, 2); // display dimentions
  lcd.setCursor(0, 0);
  lcd.print("T=");
  lcd.setCursor(2, 0); // set 
  lcd.print(temperature); // print data
  lcd.setCursor(7, 0);
  lcd.print("*C");

  lcd.setCursor(0,1); // second row
  lcd.print("H=");
  lcd.setCursor(2, 1);
  lcd.print(humidity);
  lcd.setCursor(7, 1);
  lcd.print("%");
  


}
