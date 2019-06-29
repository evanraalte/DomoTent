#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)



class bme280 {
public:
  int init(void);
  void printValues(void);
private:
  Adafruit_BME280 bme;
};