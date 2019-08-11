#include <stdio.h>
#include <string.h>
// struct SensorData {
//   float temperature;
//   float humidity;
//   int opens;
// };

union SensorDataUnion {
  struct SensorData {
    float temperature;
    float humidity;
    int opens;
  } fields;
  char bin[sizeof(struct SensorData)];
};

int main(void){
  union SensorDataUnion sensData = {0,0,0};



  printf("Size of SensorData: %d, temp: %f, humidity: %f, opens: %d"
    ,sizeof(sensData),sensData.fields.temperature
    , sensData.fields.humidity
    , sensData.fields.opens);

    char *str;
    memcpy(str, sensData.bin,sizeof sensData);
}



  // union