#include <stdio.h>
#include <SPI.h>
#include <SD.h>


class Logging {
private:

public:
  int init(char *fileName,char *options);
  int appendLine(char *line);
};
