#include <OneWire.h>
#include <DallasTemperature.h>
#include <TM1638.h>

OneWire ourWire(2);

DallasTemperature sensors(&ourWire);  //se declara una variable u objeto para nuestro sensor 

TM1638 module(8, 9, 7);

int ledR=12; // Valor de la Variable LedR
int ledV=11; // Valor de la Variable LedV
int Lec_potenciometro;
char cadena[20];
//int temp_Setup=20;

void setup() {

pinMode(ledR,OUTPUT); //Declarar ledR como salida
pinMode(ledV,OUTPUT); //Declarar ledV como salida

Serial.begin(9600);
sensors.begin(); //se inicia el sensor

//activate intensidad nivel 2
module.setupDisplay(1,4);
module.setDisplayToString("SENSOR  ",0,0);
delay(500);

}

void loop() {

Lec_potenciometro= analogRead(A0);
int temp_Setup= map(Lec_potenciometro,0,1023,25,80);

Serial.println(Lec_potenciometro);
Serial.print(temp_Setup);
Serial.println(" °C");


sensors.requestTemperatures();     //se envia el comando para leer la temperatura 
float temp=sensors.getTempCByIndex(0);    //se obtiene la temperatura en °c
             

  //enviamos la lecturs al display
  
int td=temp*10;
int ts=temp_Setup;
sprintf(cadena, "S%2d %3d*", ts,td);
  if(temp>100){
    
    module.setDisplayToString(cadena,4,0);
    }else{
      module.setDisplayToString(cadena,2,0);

      Serial.println(cadena);
      }

  
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
 
 
 module.setDisplayToString("LEC -----",0,0);
 delay(500);
}
