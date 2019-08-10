//Libraries espnow and wifi
#include <esp_now.h>
#include <WiFi.h>

// Channel used for connection
#define CHANNEL 1

// MASTER OR SLAVE
#define ESP1


// I Am....
#ifdef ESP1
uint8_t mac_addr[] = {0xA4, 0xCF, 0x12, 0x75, 0x9A, 0x5C}; //and send to ESP2
#endif

#ifdef ESP2
uint8_t mac_addr[] = {0xA4, 0xCF, 0x12, 0x75, 0x3D, 0x7C}; //and send to ESP1
#endif


// Function that will send the value to
// the peer that has the specified mac address
void send(const uint8_t *value, uint8_t *peerMacAddress) {
  esp_err_t result = esp_now_send(peerMacAddress, value, sizeof(value));
  Serial.printf("Send value %d to other esp", *value);
  // If the submission was not successful
  if (result != ESP_OK) {
    Serial.println("Error sending data");
  }

}

esp_now_peer_info_t peer;

void addPeer(uint8_t *peerMacAddress) {
  // We inform the channel
  peer.channel = CHANNEL;
  // 0 not to use encryption or 1 to use
  peer.encrypt = 0;
  // Copy array address to structure
  memcpy(peer.peer_addr, peerMacAddress, 6);
  // Add slave
  esp_now_add_peer(&peer);
}


void modeStation() {
  // We put the ESP in station mode
  WiFi.mode(WIFI_STA);
  // We show on Serial Monitor the Mac Address
  // of this ESP when in station mode
  Serial.print("Mac Address in Station: ");
  Serial.println(WiFi.macAddress());
}

void InitESPNow() {
  // If the initialization was successful
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESPNow Init Success");
  }
  // If initialization failed
  else {
    Serial.println("ESPNow Init Failed");
    ESP.restart();
  }
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}

void onDataRecv(const uint8_t *mac_addr, const uint8_t *value, int len) {
  Serial.print("Received data: ");
  Serial.println(*value);
}


void setup() {
  Serial.begin(115200);

  modeStation();
  InitESPNow();

  addPeer(mac_addr);
  // #ifdef ESP1
  esp_now_register_send_cb(OnDataSent);
  // #endif

  // #ifdef ESP2
  esp_now_register_recv_cb(onDataRecv);
  // #endif
}

uint8_t val = 0;

void loop(){
  send(&val, mac_addr);
  val++;
  delay(2000);
}

