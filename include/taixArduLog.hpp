#ifndef taixArduLog_hpp
#define taixArduLog_hpp

#include "Arduino.h"
#include "time.h"

/**
 * @author TaixMiguel
 */
class TaixArduLog {

  typedef void (*FunctionCallbackLog) (const String msg, const String raw);

  public:
    TaixArduLog();
    void begin(bool devMode, int levelLog);
    void setCallback(FunctionCallbackLog fCallbackLog);

    void log(const char* level, const char* text);

  private:
    bool _devMode;
    int _levelLog;
    FunctionCallbackLog _fCallbackLog;
};

#endif