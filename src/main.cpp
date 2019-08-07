/*
* Arduino Wireless Communication Tutorial
*     Example 2 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
// #include <DigitalIO.h>



RF24 radio(SCK,MISO,MOSI,22,23); // CE, CSN




// #define ERIK
#define JOOST
// #define BEREND



#define ADDR_ERIK "00001"
#define ADDR_JOOST "00002"
#define ADDR_BEREND "00003"
/*
 * Erik   -> "00001"
 * Joost  -> "00002"
 * Berend -> "00003"
 *
 */




#ifdef ERIK
  const byte writeAddr[][6] = {ADDR_JOOST, ADDR_BEREND};
  const byte readAddr[][6] = {ADDR_JOOST, ADDR_BEREND};

  #define STARTTIME 0
  #define ENDTIME 5
#endif

#ifdef JOOST
  const byte writeAddr[][6] = {ADDR_ERIK, ADDR_BEREND};
  const byte readAddr[][6] = {ADDR_ERIK, ADDR_BEREND};

  #define STARTTIME 20
  #define ENDTIME 25

#endif

#ifdef BEREND
  const byte writeAddr[][6] = {ADDR_ERIK, ADDR_JOOST};
  const byte readAddr[][6] = {ADDR_ERIK, ADDR_JOOST};

  #define STARTTIME 40
  #define ENDTIME 45
#endif






boolean buttonState = 0;

void setup() {

  Serial.begin(115200);
  Serial.printf("Starting app as %s",ADDR_ERIK);
  pinMode(12, OUTPUT);
  radio.begin();
  // radio.openWritingPipe(writeAddr[0]);
  // radio.openWritingPipe(writeAddr[1]);

  radio.setChannel(2);
  radio.setPayloadSize(32);

  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);

  radio.openReadingPipe(1, readAddr[0]);
  radio.openReadingPipe(2, readAddr[1]);
}





enum State {listen, sendSensor, sendMessage};

enum State state = listen; 

int timeSeconds = 0;


void buildSensorMessage(int temperature,int humidity, int opens, char str[]){
  temperature = temperature % 999;
  humidity = humidity % 999;
  opens = opens % 999;

  // char sTemperature[4];
  // char sHumidity[4];
  // char sOpens[4];

  // itoa(temperature,sTemperature,10);
  // itoa(humidity,sHumidity,10);
  // itoa(opens,sOpens,10);

  char cName;
  #ifdef ERIK
    cName = 'E';
  #endif
  #ifdef JOOST
    cName = 'J';
  #endif
  #ifdef BEREND
    cName = 'B';
  #endif


  sprintf(str,"S;%c;%03d;%03d;%03d;.",cName,temperature,humidity,opens);

}


void loop() {
  
  // Serial.printf("time: %d\n",timeSeconds);

  if(timeSeconds == STARTTIME){ //only start when it is exactly the right time
    state = sendSensor;
  } else if(timeSeconds >= ENDTIME || timeSeconds < STARTTIME){
    state = listen;
    radio.startListening();
  }

  if(state == sendSensor){
    radio.stopListening();
    //build message
    char sendStr [32];
    buildSensorMessage(200,300,400,sendStr);

    Serial.printf("Send sensors... msg: %s\n",sendStr);
    radio.openWritingPipe(writeAddr[0]);
    radio.write(&sendStr, sizeof(sendStr));

    radio.openWritingPipe(writeAddr[1]);
    radio.write(&sendStr, sizeof(sendStr));

    state = sendMessage;
  } else if(state == sendMessage ){
      Serial.printf("Send message...\n");
      //build message
      // char msg [32] = "derp";
      // radio.write(&msg, sizeof(msg));
      delay(5);
      radio.startListening();
      state = listen;
  } else if (state == listen){

    // Serial.printf("listening...\n");

    if( radio.available()){


      char receiveStr [32] = "";
                                                              // Variable for the received timestamp
      while (radio.available()) {                                   // While there is data ready
        radio.read( &receiveStr, sizeof(receiveStr) );                            // Get the payload
      }
     
      Serial.printf("Received a string: %s\n",receiveStr);  

      //TODO: decoden etc, eerst maar eens zien of dit werkt
   }
  }

  timeSeconds = (timeSeconds + 1) % 60; // temporary workaround until RTC is implemented
  delay(100);
}



