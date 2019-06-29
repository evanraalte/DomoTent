#include <stdio.h>
#include <SPI.h>
#include <SD.h>


class Logging {
private:
  File logFile;
  char fileName[100];
  
public:
  int init(const char *fileNameInit);

  int appendfile(const char *line);
};
