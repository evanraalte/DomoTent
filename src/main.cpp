#include <Arduino.h>
#include <e-ink.h>



void setup()
{
    Serial.begin(115200);
    delay(500);
    SPI.begin(SPI_CLK, SPI_MISO, SPI_MOSI, -1);
    if (!FILESYSTEM.begin())
    {
        Serial.println("FILESYSTEM is not database");
        Serial.println("Please use Arduino ESP32 Sketch data Upload files");
        while (1)
        {
            delay(1000);
        }
    }
    showMainPage();
    drawGrid();
    update();
}
 
void loop()
{
  
}

