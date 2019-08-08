//includes
#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <GxGDEH0213B72/GxGDEH0213B72.h> 

#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMonoBoldOblique9pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSansBoldOblique9pt7b.h>
#include <Fonts/FreeSansOblique9pt7b.h>

#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeSerifBold9pt7b.h>
#include <Fonts/FreeSerifBoldItalic9pt7b.h>
#include <Fonts/FreeSerifItalic9pt7b.h>
#include "SD.h"
#include "SPI.h"
#include <SPIFFS.h>
#include "Esp.h"
#include "IMG_0001.h"

#define DEFALUT_FONT FreeSans9pt7b

#define DEFALUT_AVATAR_BMP "/avatar.bmp"
#define DEFALUT_QR_CODE_BMP "/qr.bmp"


#define FILESYSTEM SPIFFS

typedef enum
{
    RIGHT_ALIGNMENT = 0,
    LEFT_ALIGNMENT,
    CENTER_ALIGNMENT,
} Text_alignment;
// function definitions

void displayText(const String &str, int16_t y, uint8_t alignment);

void displayInit(void);

uint16_t read16(File &f);

uint32_t read32(File &f);

void drawBitmap(const char *filename, int16_t x, int16_t y, bool with_color);

void showMainPage(void);

void drawGrid(void);

void update(void);


