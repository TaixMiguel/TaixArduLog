#include "taixArduLog.hpp"

String _app, _device;
const char* _serverName;
bool freeConnection = true;
TaixArduLog::TaixArduLog() {}

void TaixArduLog::init(char* serverName, String app, String device) {
  esp_log_set_vprintf(taixLogger);
  _serverName = serverName;
  _device = device;
  _app = app;
}

void TaixArduLog::setLevelLog(char* tag, esp_log_level_t levelLog) {
  esp_log_level_set(tag, levelLog);
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

int TaixArduLog::taixLogger(const char* format, va_list args) {
  char bufferLog[1024];
  int retorno = vsnprintf(bufferLog, sizeof(bufferLog), format, args);
  String msg = "[" + getTimeLog() + "]" + bufferLog;

  if (freeConnection) {
    Serial.print("--> " + msg);
    if (WiFi.status() == WL_CONNECTED) {
      freeConnection = false;
      WiFiClient client;
      HTTPClient http;

      http.begin(client, _serverName);
      msg = msg.substring(0, msg.length()-1);
      http.addHeader("Content-Type", "application/json");
      http.POST("{\"app\":\""+_app+"\",\"device\":\""+_device+"\",\"msg\":\""+String(msg)+"\"}");
      http.end();
      freeConnection = true;
    }
  }

  return retorno;
}