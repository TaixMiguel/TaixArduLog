# TaixArduLog

Una librería para enviar logs a un servidor web.

## Tipos de logs:
| Código 	          | Nivel |
|---	              |---	  |
| `ESP_LOG_NONE`    |0  	  |
| `ESP_LOG_ERROR`   |1  	  |
| `ESP_LOG_WARN` 	  |2  	  |
| `ESP_LOG_INFO` 	  |3  	  |
| `ESP_LOG_DEBUG`   |4  	  |
| `ESP_LOG_VERBOSE` |5      |

## Uso:
Se puede instanciar la clase de la siguiente forma:

``` C++
TaixArduLog taixLog;
taixLog.init("http://IP:PORT/", "$APP", "$DEVICE");
taixLog.setLevelLog("*", ESP_LOG_VERBOSE);
```

En `platformio.ini` añadir los siguientes flags:
```
build_flags =
  -DCORE_DEBUG_LEVEL=5
  -DUSE_ESP_IDF_LOG
```