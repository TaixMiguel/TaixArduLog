#include "taixArduLog.hpp"

void callbackDefault(String msg, String raw) {}

TaixArduLog::TaixArduLog() {}

void TaixArduLog::begin(bool devMode, int levelLog) {
  this->fCallbackLog = callbackDefault;
  this->levelLog = levelLog;
  this->devMode = devMode;
}

void TaixArduLog::setCallback(FunctionCallbackLog fCallbackLog) {
  this->fCallbackLog = fCallbackLog;
}

int getLevelNumber(const char* level) {
  if (!strcmp("DEBUG",  level)) return 1;
  if (!strcmp("INFO",   level)) return 2;
  if (!strcmp("CONF",   level)) return 3;
  if (!strcmp("WARN",   level)) return 4;
  if (!strcmp("ERROR",  level)) return 5;
  if (!strcmp("FATAL",  level)) return 6;
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
  if (devMode) {
      String msg = "[" + getTimeLog() + "][" + String(level) + "] " + text;
      if (levelLog > 0 && getLevelNumber(level) >= levelLog)
          fCallbackLog(msg, text);
      Serial.println("--> " + msg);
  }
}