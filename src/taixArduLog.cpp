#include "taixArduLog.hpp"

void callbackDefault(String msg, String raw) {}

String _serverName, _app, _device;
void callbackServer(String msg, String raw) {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, _serverName);
    http.addHeader("Content-Type", "application/json");
    http.POST("{\"app\":\""+_app+"\",\"device\":\""+_device+"\",\"msg\":\""+msg+"\"}");
    http.end();
  }
}

TaixArduLog::TaixArduLog() {}

void TaixArduLog::begin(int levelLog) {
  this->fCallbackLog = callbackDefault;
  this->levelLog = levelLog;
}

void TaixArduLog::begin(int levelLog, String serverName, char* app, String device) {
  this->fCallbackLog = callbackServer;
  this->levelLog = levelLog;
  _serverName = serverName;
  _app = String(app);
  _device = device;
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
  String msg = "[" + getTimeLog() + "][" + String(level) + "] " + text;
  if (levelLog > 0 && getLevelNumber(level) >= levelLog)
    fCallbackLog(msg, text);
  Serial.println("--> " + msg);
}