#include "Logging.h"

int Logging::init(const char *fileNameInit){
    SPIClass sdSPI(VSPI);
    sdSPI.begin(SDCARD_CLK, SDCARD_MISO, SDCARD_MOSI, SDCARD_SS);

    if(!SD.begin(SDCARD_SS,sdSPI)){
        Serial.println("Card Mount Failed");
        return 1;
    }

    uint8_t cardType = SD.cardType();

    if(cardType == CARD_NONE){
        Serial.println("No SD card attached");
        return 1;
    }

    Serial.print("SD Card Type: ");
    if(cardType == CARD_MMC){
        Serial.println("MMC");
    } else if(cardType == CARD_SD){
        Serial.println("SDSC");
    } else if(cardType == CARD_SDHC){
        Serial.println("SDHC");
    } else {
        Serial.println("UNKNOWN");
    }

    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %lluMB\n", cardSize);
    return 0;
    strcpy(fileName,fileNameInit);
    Serial.printf("Set logfile to: %s\n", fileName);
}

int Logging::appendfile(const char *line){
    Serial.printf("Appending to file: %s\n", fileName);
    logFile = SD.open(fileName,FILE_APPEND);
    if(!logFile){
      Serial.println("Failed to open file for appending");
      return 1;
    }
    if(logFile.print(line)){
        Serial.printf("Message appended\n:%s",line);
    } else {
        Serial.println("Append failed");
    }
    logFile.close();

    return 0;
}