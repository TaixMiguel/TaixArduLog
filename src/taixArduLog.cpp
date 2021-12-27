#include "taixArduLog.hpp"

void callbackDefault(String msg, String raw) {}

TaixArduLog::TaixArduLog() {}

void TaixArduLog::begin(bool devMode, int levelLog) {
  _fCallbackLog = callbackDefault;
  _levelLog = levelLog;
  _devMode = devMode;
}

void TaixArduLog::setCallback(FunctionCallbackLog fCallbackLog) {
  _fCallbackLog = fCallbackLog;
}

int getLevelNumber(const char* level) {
    if ("DEBUG" == level) return 1;
    if ("INFO" == level)  return 2;
    if ("CONF" == level)  return 3;
    if ("WARN" == level)  return 4;
    if ("ERROR" == level) return 5;
    if ("FATAL" == level) return 6;
    return 0;
}

String getTimeLog() {
  time_t timer;
  char buffer[20];
  struct tm* tmInfo;

  timer = time(NULL);
  tmInfo = localtime(&timer);
  strftime(buffer, 20, "%Y/%m/%d %H:%M:%S", tmInfo);
  return buffer;
}

void TaixArduLog::log(const char* level, const char* text) {
  if (_devMode) {
      String msg = "[" + getTimeLog() + "][" + String(level) + "] " + text;
      if (_levelLog > 0 && getLevelNumber(level) >= _levelLog)
          _fCallbackLog(msg, text);
      Serial.println("--> " + msg);
  }
}