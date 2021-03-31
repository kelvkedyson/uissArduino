/*
  Written by : Kelvin Kedyson Zacharia
  BSC Telecommunications Engineering (UDSM - CoICT)
  Wednesday, March 31st 2021
*/

//importing the libraries
#include <LiquidCrystal.h>
#include <SimpleDHT.h>

int pinDHT11 = 4;
SimpleDHT11 dht11;

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Temperature and Humidity Control System");
  
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  
  Serial.println("");
  
  Serial.print("Results: ");
  Serial.print((int)temperature);
  Serial.print(" *C, ");
  Serial.print((int)humidity);
  Serial.println(" %");

  lcd.setCursor(0, 1);
  lcd.print("Temperature:");
  
  // DHT11 sampling rate is 1HZ.
  delay(1000);
}
