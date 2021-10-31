# TaixArduLog

Una librería para escribir logs en Arduino que principalmente se visualizan en la consola, pero con la posibilidad de generarlos dónde te interese gracias a una función callback.

## Tipos de logs:
| Código 	| Nivel | 
|---	    |---	|
| `INFO` 	|1  	|
| `CONF` 	|2  	|
| `NOTICE`  |3  	|
| `WARN`    |4  	|
| `ERROR`   |5  	|

En función del nivel con que se instancia la clase `TaixArduLog`, se verán los diferentes errores. Es decir, si se instancia con el nivel 3, sólo se verán los errores de tipo `NOTICE`, `WARN` y `ERROR`.


## Uso:
Se puede instanciar la clase de la siguiente forma:

``` C++
TaixArduLog taixLog();
taixLog.begin(true, 3);
```

O creando nuestra propia función callback:

``` C++
void callbackTest(String msg, String raw) {
  Serial.println("Mensaje entero:");
  Serial.println(msg);
  Serial.println();
  Serial.println("Mensaje en crudo:");
  Serial.println(raw);
}

TaixArduLog taixLog();
taixLog.begin(true, 3);
taixLog.setCallback(callbackTest);
```

y es tan fácil de utilizar como llamar al método log

``` C++
taixLog.log("NOTICE", "Este es un mensaje de prueba");
```


### Ejemplo completo

``` C++
void callbackTest(String msg, String raw) {
  Serial.println("Mensaje entero:");
  Serial.println(msg);
  Serial.println();
  Serial.println("Mensaje en crudo:");
  Serial.println(raw);
}

TaixArduLog taixLog();
taixLog.begin(true, 3);
taixLog.setCallback(callbackTest);

taixLog.log("NOTICE", "Este es un mensaje de prueba");
```

### Salida del ejemplo

``` C++
[YYYY/mm/dd HH:MM:SS][NOTICE] Este es un mensaje de prueba
Mensaje entero:
[YYYY/mm/dd HH:MM:SS][NOTICE] Este es un mensaje de prueba

Mensaje en crudo:
Este es un mensaje de prueba
```