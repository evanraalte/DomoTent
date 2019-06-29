#include "bme280.h"

int bme280::init(){
  // bme = Adafruit_BME280(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI
  
  // ~Wire(); //descruct default Wire instantiation
  // i2c = TwoWire(0); //Use first i2c peripheral
  Wire.begin(SDA,SCL);
  
  int status = bme.begin();
  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    return 1;
  } 
  return 0;
}

void bme280::printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}