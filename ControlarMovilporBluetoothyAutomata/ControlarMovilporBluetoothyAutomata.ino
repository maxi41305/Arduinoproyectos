/*
Controlar Movil por Bluetooth y Autómata

Conexion del Modulo Bluetooth HC-06 y el Arduino
 ARDUINO    Bluetooth HC-06 
 5 (RX)       TX
 6 (TX)       RX
 5V           VCC
 GND          GND
 !!Cuidado!! Las conexiones de TX y RX al modulo Bluetooth deben estar desconectadas
 en el momento que se realiza la carga del codigo (Sketch) al Arduino.
 
 Conexion Sensor Ultrasonido HC-SR04
 ARDUINO    Ultrasonido HC-SR04 
 2            Echo
 3            Trig
 5V           VCC
 GND          Gnd
*/

#include <SoftwareSerial.h>       //Importar Software de Librerìa
SoftwareSerial myStream(5, 6);    //Definir Pines para Rx y Tx respectivamente

int ledR=13; // Valor de la Variable LedR
int ledV=12; // Valor de la Variable LedV
int ledA=11; // Valor de la Variable LedA

int MDA=10;  // Variable Motor Derecho Adelante
int MDR=9;   // Variable Motor Derecho Atras
int MIA=8;   // Variable Motor Izquierdo Adelante
int MIR=7;   // Variable Motor Izquierdo Atras

int pecho = 2;            // define el pin 2 como (eco) para el Ultrasonido
int ptrig = 3;            // define el pin 3 como (disparo) para el Ultrasonido
int duracion, distancia;  // para Calcular distacia
char teclado='x';

void setup() {
pinMode(ledR,OUTPUT); //Declarar ledR como salida
pinMode(ledV,OUTPUT); //Declarar ledV como salida
pinMode(ledA,OUTPUT); //Declarar ledA como salida

pinMode(MDA,OUTPUT); //Declarar MDA como salida
pinMode(MDR,OUTPUT); //Declarar MDR como salida
pinMode(MIA,OUTPUT); //Declarar MIA como salida
pinMode(MIR,OUTPUT); //Declarar MIR como salida

pinMode(pecho,INPUT);
pinMode(ptrig,OUTPUT);
digitalWrite(ptrig,LOW);

Serial.begin(9600);
myStream.begin(9600);
}

void loop() { 

   while (myStream.available())    //Si el cliente Bluetooth está disponible
  {
    teclado = myStream.read();    //Lectura desde el Bluetooth
   Serial.println(teclado);
  }
  //if (Serial.available()>0){
 //      teclado=Serial.read();
    if (teclado== 'r'){     
digitalWrite(ledR,HIGH); //Encendido Rojo
digitalWrite(MDA,LOW);   //Apagado Motor Derecho Adelante
digitalWrite(MIA,LOW);   //Apagado Motor Izquierdo Adelante
digitalWrite(MDR,HIGH);  //Encendido Motor Derecho Atras
digitalWrite(MIR,HIGH);  //Encendido Motor Izquierdo Atras

}
        if (teclado== 'a'){     
digitalWrite(ledV,HIGH); //Encendido Verde
digitalWrite(MDR,LOW);   //Apagado Motor Derecho Atras
digitalWrite(MIR,LOW);   //Apagado Motor Izquierdo Atras
digitalWrite(MDA,HIGH); //Encendido Motor Derecho Adelante
digitalWrite(MIA,HIGH); //Encendido Motor Izquierdo Adelante
}
   if (teclado== 'd'){     
digitalWrite(ledA,HIGH); //Encendido Verde
digitalWrite(MDR,LOW);  //Apagado Motor Derecho Atras
digitalWrite(MIR,LOW); //Apagado Motor Izquierdo Atras
digitalWrite(MDA,HIGH); //Encendido Motor Derecho Adelante
digitalWrite(MIA,LOW); //Encendido Motor Izquierdo Adelante
}
   if (teclado== 'i'){     
digitalWrite(ledA,HIGH); //Encendido Verde
digitalWrite(MDR,LOW); //Apagado Motor Derecho Atras
digitalWrite(MIR,LOW); //Apagado Motor Izquierdo Atras
digitalWrite(MDA,LOW); //Apagado Motor Derecho Adelante
digitalWrite(MIA,HIGH); //Encendido Motor Izquierdo Adelante
}

if (teclado== 'f'){ 
digitalWrite(ptrig, HIGH);
     delayMicroseconds(10);
     digitalWrite(ptrig,LOW); 
     duracion = pulseIn(pecho, HIGH);       // Lee el tiempo del Eco
     distancia = (duracion/2) / 29.1;        // Calcula la distancia en centimetros 
    Serial.print("Distancia: ");
    Serial.println(distancia);
     if (distancia <= 15 && distancia >=2){     // si la distancia es menor de 15cm
        digitalWrite(ledR,HIGH);                 // Enciende LED
        digitalWrite(ledV,LOW);
        
        digitalWrite(MDR, LOW);                  // Parar los motores por 200 milsegundos
        digitalWrite(MIR, LOW); 
        digitalWrite(MDA, LOW);    
        digitalWrite(MIA, LOW); 
        delay (200);
        
        digitalWrite(MDR, HIGH);               // Reversa durante 500 milisegundos
        digitalWrite(MIR, HIGH); 
        delay(500);           
        
        digitalWrite(MDR, LOW);                // Girar durante 100 milisegundos   
        digitalWrite(MIR, LOW); 
        digitalWrite(MDA, LOW);  
        digitalWrite(MIA, HIGH);  
        delay(100);
        
        
     }
     else{                                 // Si no hay obstaculos se desplaza al frente  
         digitalWrite(ledV,HIGH);
         digitalWrite(ledR,LOW);
         digitalWrite(MDR, LOW);     
         digitalWrite(MIR, LOW); 
         digitalWrite(MDA, HIGH);  
         digitalWrite(MIA, HIGH); 
     }

  
}



if (teclado== 'x'){      
digitalWrite(ledR,LOW); //Apagado
digitalWrite(ledV,LOW); //Apagado
digitalWrite(ledA,LOW); //Apagado

digitalWrite(MDR,LOW); //Apagado Motor Derecho Atras
digitalWrite(MIR,LOW); //Apagado Motor Izquierdo Atras
digitalWrite(MDA,LOW); //Apagado Motor Derecho Adelante
digitalWrite(MIA,LOW); //Apagado Motor Izquierdo Adelante
}
//  }
}
