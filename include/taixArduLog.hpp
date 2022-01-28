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

  typedef void (*FunctionCallbackLog) (const String msg, const String raw);

  public:
    TaixArduLog();
    void begin(int levelLog);
    void begin(int levelLog, String serverName, char* app, String device);
    void setCallback(FunctionCallbackLog fCallbackLog);

    void log(const char* level, const char* text);

  private:
    int levelLog;
    FunctionCallbackLog fCallbackLog;
};

#endif