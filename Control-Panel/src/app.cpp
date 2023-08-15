#include "app.h"
#include "ota.h"
#include "communication.h"

void app_begin(){
    communication_begin();
    ota_begin();    
}

void app_run(){
    communication_run();
    ota_run();
}