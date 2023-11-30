/*
 * Sensor de proximidad por Ultrasonido PRENDER Y APAGAR LED DEPENDE SU DISTANCIA
 */
int pecho = 2;            // define el pin 2 como (eco) para el Ultrasonido
int ptrig = 3;            // define el pin 3 como (disparo) para el Ultrasonido
int duracion, distancia;  // para Calcular distacia
int ledR = 13;            // variable led donde estara conectado en la placa arduinio
int ledV = 12;
int ledA = 11;

void setup() {
 
pinMode(ledR,OUTPUT);                 //declarar ledR como salida 
pinMode(ledV,OUTPUT); 
pinMode(ledA,OUTPUT); 

  pinMode(ptrig,OUTPUT);                  
pinMode(pecho,INPUT);
digitalWrite(ptrig,LOW);
Serial.begin(9600);
}

void loop() {


  
     digitalWrite(ptrig, HIGH);
     delayMicroseconds(10);
     digitalWrite(ptrig,LOW); 
     duracion = pulseIn(pecho, HIGH);      // Lee el tiempo del Eco
     distancia = (duracion/2) / 29.1;        // calcula la distancia en centimetros 
 Serial.println(distancia);
 delay(1000);
  if(distancia<5){
     digitalWrite(ledR,HIGH); //prende rojo
      digitalWrite(ledV,LOW); 
       digitalWrite(ledA,LOW); 
      
      
      Serial.print("Distancia: ");
Serial.println(distancia);
    }else{
          if(distancia>15){
             digitalWrite(ledR,LOW);
      digitalWrite(ledV,HIGH); //prende verde
       digitalWrite(ledA,LOW); 
        Serial.print("Distancia: ");
            }else{
               digitalWrite(ledR,LOW); 
      digitalWrite(ledV,LOW); 
       digitalWrite(ledA,HIGH); //prende amarillo
            Serial.print("Distancia: ");
Serial.println(distancia);
              
              }
      
       
      }


    


}
