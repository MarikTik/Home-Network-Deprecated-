#include "components/communication.h"
#include "log.h"
#include <ESP8266WiFi.h>



void serial_begin(){
    Serial.begin(SERIAL_BAUD_RATE); 
}

void wifi_begin(){
  log_v("Booting:");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    log_e("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  log_i_f("Local IP\t%s", WiFi.localIP().toString().c_str());
}

void communication_begin(){
  serial_begin();
  wifi_begin();
}
void communication_run(){

}
