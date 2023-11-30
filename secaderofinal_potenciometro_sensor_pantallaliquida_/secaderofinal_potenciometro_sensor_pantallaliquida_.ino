/*
 * Termómetro 
 * Setup controladado por potenciómetro
 * Leds indicadores de rango
 * Display TM1638
 */
#include <DHT.h>
#include "DHT.h" 
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //pantalla de liquido para imprecion en pantalla


//Variables
#define DHTPIN 2
#define DHTTYPE DHT22
int retardo = 1000; //re1tardo entre lecturas
DHT dht(DHTPIN, DHTTYPE);

char array1[]="      Maxi        ";
char array2[]="  SECADERO DE MADERA ";
char array3[]="  CONTROLADOR PORT  ";
char array4[]="      ARDUINO       ";

char cadenaSP[20];
char cadenaME[20];
char cadenaVE[20];

int hsp=40; 
int tsf=50;
int Vent=1000;

void setup() {
Serial.begin(9600);
Serial.println("prueba del DHT221");
dht.begin();

lcd.init(); //inicializa el led
lcd.blacklight(); //ilumina el fondo
pantalla(0,0,array1);
pantalla(0,1,array2);
pantalla(0,2,array3);
pantalla(0,3,array4);
delay(2000);
lcd.clear();

}
 
void loop() {
lcd.clear();

float h = dht.readHumidity();  // lee humedad
float t = dht.readTemperature();  //lee temperatura

if(isnan(h) || isnan (t)){
  
  Serial.println("falla de lecturaa en el sensor DHT1");
  return;
  }

int Temp=t;
int Hum=h;
 sprintf(array2,"S.P Hum%3d Temp%3d*C",hsp,tsf);
 sprintf(array3,"Med Hum%3d Temp%3d*C",Hum,Temp);
 sprintf(array4,"Ventana Tiem : %3d",Vent);
 lcd.clear();
 pantalla(0,0,array1);
 pantalla(0,1,array2);
 pantalla(0,2,array3); 
pantalla(0,3,array4);

 delay(retardo);
  Serial.print("humedad: "); 
   Serial.print(h); 
    Serial.print("%"); 
Serial.print(" Temperatura: "); 
Serial.print(t); 
Serial.print("  *C "); 

}
int pantalla(int columna, int fila, char texto[]);
lcd.setCursor(columna, fila);
for (int c=0;c<=19;c++){
  led.print(texto[c]);
  }
