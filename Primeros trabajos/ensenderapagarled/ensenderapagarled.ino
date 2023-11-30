
//ensender y apagar un led:

int ledR = 13;            // variable led donde estara conectado en la placa arduinio
int ledV = 12;
int teclado='x';
int motorDerechoAdelante = 10;    //motor derecho adelante
int motorderechoRetroseso = 9; //motor derecho atras
int motorIzquierdoAdelante = 8; //motor izquierdo adelante
int motorizquierdoRetroseso = 7; ////motor izquierdo atras

void setup() {

pinMode(ledR,OUTPUT);                 //declarar ledR como salida 
pinMode(ledV,OUTPUT);                 //declarar ledV como salida 
pinMode(motorDerechoAdelante,OUTPUT);
pinMode(motorderechoRetroseso,OUTPUT);
pinMode(motorIzquierdoAdelante,OUTPUT);
pinMode(motorizquierdoRetroseso,OUTPUT);
Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0){
    teclado=Serial.read();

         if(teclado=='a'){                     //preguntamos si la letra ingresada es x que se ensienda 
           digitalWrite(ledV,HIGH);              //ensiende led
           digitalWrite(motorDerechoAdelante,HIGH);              
           digitalWrite(motorIzquierdoAdelante,HIGH); 
            digitalWrite(motorizquierdoRetroseso,LOW); 
           digitalWrite(motorderechoRetroseso,LOW);       
        //delay(5000);                          //un retardo de 1 segundo

    }
        
        if(teclado=='r'){                     //preguntamos si la letra ingresada es x que se ensienda 
           digitalWrite(ledR,HIGH);              //ensiende led
           digitalWrite(motorderechoRetroseso,HIGH);              
           digitalWrite(motorizquierdoRetroseso,HIGH);  
           digitalWrite(motorDerechoAdelante,LOW);              
           digitalWrite(motorIzquierdoAdelante,LOW);            
        //delay(5000);                          //un retardo de 1 segundo
        }
            if(teclado=='x'){
           digitalWrite(ledR,LOW);               //apaga led 
           digitalWrite(ledV,LOW);              //apaga led
           digitalWrite(motorderechoRetroseso,LOW);   //apagar motor derecho atras           
           digitalWrite(motorizquierdoRetroseso,LOW); //aoagar motor izquierdo atras
           digitalWrite(motorDerechoAdelante,LOW);    //apagar motor derecho adelante           
           digitalWrite(motorIzquierdoAdelante,LOW);  //apagar motor izquierdo adelante 
            
            //delay(1000);                          //un retardo de 1 segundo
    }
    }
                  
}
