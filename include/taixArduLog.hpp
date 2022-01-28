#ifndef taixArduLog_hpp
#define taixArduLog_hpp

#include "Arduino.h"
#include <HTTPClient.h>
#include "time.h"
#include <WiFi.h>

/**
 * @author TaixMiguel
 */
class TaixArduLog {

  public:
    TaixArduLog();
    void init(String serverName, char* app, String device);
    void setLevelLog(char* tag, esp_log_level_t levelLog);
    void setLevelLog(char* tag, int level);

  private:
    static int taixLogger(const char* format, va_list args);
};

#endif