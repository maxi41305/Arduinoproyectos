#include <DHT.h>
#include <DHT_U.h>


/*
 * Prueba del DHT22
 */

#include "DHT.h"
#define DHTPIN 2    


//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22     // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Prueba del DHT22!");
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();     // Lee Humedad
  float t = dht.readTemperature(); // Lee Temperatura
  
  if (isnan(h) || isnan(t) ) {
    Serial.println("Falla en la lectura del sensor DHT !");
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%");
   Serial.print("     Temperatura: ");
  Serial.print(t);
  Serial.println(" *C ");
  
}
