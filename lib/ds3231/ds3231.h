#include <Wire.h>
#include <RtcDS3231.h>
#define countof(a) (sizeof(a) / sizeof(a[0]))

class ds3231 {
public:
  int init(void);
  void printDateTime(const RtcDateTime& dt);
private:
  RtcDS3231<TwoWire> rtc;
};



