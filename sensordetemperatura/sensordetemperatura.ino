#include <OneWire.h>
#include <DallasTemperature.h>


OneWire ourWire(2);

DallasTemperature sensors(&ourWire);  //se declara una variable u objeto para nuestro sensor 
int ledR=12; // Valor de la Variable LedR
int ledV=11; // Valor de la Variable LedV
int Lec_potenciometro;
//int temp_Setup=20;

void setup() {
pinMode(ledR,OUTPUT); //Declarar ledR como salida
pinMode(ledV,OUTPUT); //Declarar ledV como salida

Serial.begin(9600);
sensors.begin(); //se inicia el sensor
}

void loop() {

Lec_potenciometro= analogRead(A0);
int temp_Setup= map(Lec_potenciometro,0,1023,25,80);

Serial.println(Lec_potenciometro);
Serial.print(temp_Setup);
Serial.println(" °C");


sensors.requestTemperatures();     //se envia el comando para leer la temperatura 
float temp=sensors.getTempCByIndex(0);    //se obtiene la temperatura en °c
             

  
  
  
  digitalWrite(ledR,LOW);  
  digitalWrite(ledV,LOW);


if(temp<temp_Setup){
   digitalWrite(ledV,HIGH); 
   digitalWrite(ledR,LOW);
  
  }

    if(temp>=temp_Setup){
      digitalWrite(ledR,HIGH); 
     digitalWrite(ledV,LOW);
      }
    



Serial.print("Temperatura: ");
Serial.print(temp);
Serial.println(" °C");
delay(1000);

}
