#include <Arduino.h>
#include <bme280.h>

bme280 bme;

void setup() {
  Serial.begin(115200);
  bme.init();
  // put your setup code here, to run once:
}

void loop() {
  bme.printValues();
  delay(2000);
  // put your main code here, to run repeatedly:
}