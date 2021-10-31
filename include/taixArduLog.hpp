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
    TaixArduLog(bool devMode, int levelLog);
    TaixArduLog(bool devMode, int levelLog, FunctionCallbackLog fCallbackLog);
    void log(const char* level, const char* text);

  private:
    bool _devMode;
    int _levelLog;
    FunctionCallbackLog _fCallbackLog;
};

#endif