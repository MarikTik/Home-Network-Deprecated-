#include "components/filesystem.h"
#include "log.h"
#include <LittleFS.h>


void filesystem_begin(){
 if(!LittleFS.begin()) log_e("failed to begin littlefs");
 log_v("littlefs initialized successfully");
}

void filesystem_run(){

}