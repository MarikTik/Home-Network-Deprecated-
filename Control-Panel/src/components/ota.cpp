#include "components/ota.h"
#include <ArduinoOTA.h>
#include "log.h"

void ota_set_callbacks(){
    ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      log_i("Start updating sketch");
    } else {  // U_FS
      log_i("Start updating filesystem");
    }
    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
  });

  ArduinoOTA.onEnd([]() {
    log_i("\nEND");
  });
  
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    log_i_f("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    log_e("--Error--");
    if (error == OTA_AUTH_ERROR) {
      log_e("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      log_e("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      log_e("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      log_e("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      log_e("End Failed");
    }
  });
}
void ota_begin(){ 
    ota_set_callbacks();
    ArduinoOTA.setPort(OTA_UPLOAD_PORT);
    ArduinoOTA.setHostname(HOSTNAME);
    ArduinoOTA.begin();
}

void ota_run(){
    ArduinoOTA.handle();
}