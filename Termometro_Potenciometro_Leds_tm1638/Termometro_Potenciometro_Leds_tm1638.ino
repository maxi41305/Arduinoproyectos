/*
 * Termómetro 
 * Setup controladado por potenciómetro
 * Leds indicadores de rango
 * Display TM1638
 */

#include <OneWire.h>                
#include <DallasTemperature.h>
#include <TM1638.h>


OneWire ourWire(2);                  //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

//pines (I/O) pin 8, clock(CLK) pin 9 , strobe(STB) pin 7
TM1638 module(8, 9, 7);

int Lec_Potenciometro;
int LedR=12;
int LedV=11;
char cadena[20];

void setup() {
Serial.begin(9600);
sensors.begin();   //Se inicia el sensor
pinMode(LedR,OUTPUT);
pinMode(LedV,OUTPUT);
digitalWrite(LedR,LOW);
digitalWrite(LedV,LOW);

//activa intensidad con nivel 2
  module.setupDisplay(1,4);
  module.setDisplayToString("SENSOR  ",0,0);
  delay(500);
}
 
void loop() {
 Lec_Potenciometro= analogRead(A0);
float Temp_Setup=map(Lec_Potenciometro,0,1023,15,80);
Serial.println(Lec_Potenciometro);
 Serial.print(Temp_Setup);
Serial.println(" C");

sensors.requestTemperatures();         //Se envía el comando para leer la temperatura
float Temp= sensors.getTempCByIndex(0);  //Se obtiene la temperatura en ºC

//--------Enviamos las lecturas al display ------------
  int td=Temp*10;
  int ts=Temp_Setup;
  sprintf(cadena,"S%2d %3d*",ts,td);
      if(Temp>-100)  
      {module.setDisplayToString(cadena,4,0);}
        else
        {module.setDisplayToString(cadena,2,0);}
      Serial.println(cadena);   
      
//Serial.print("Temperatura= ");
//Serial.print(Temp);
//Serial.println(" C");
if ((Temp<=Temp_Setup)){
   digitalWrite(LedR,HIGH);
   digitalWrite(LedV,LOW);
  }
  if ((Temp>Temp_Setup)) {
  digitalWrite(LedV,HIGH);
   digitalWrite(LedR,LOW);   
  }
   
delay(1000);
 module.setDisplayToString("LEC -----",0,0);
  delay(500);                     
}
