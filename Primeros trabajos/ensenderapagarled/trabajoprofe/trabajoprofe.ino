#include <SoftwareSerial.h>       //importar la librferia Software Serial
SoftwareSerial myStream(5, 6);   //pins for Rx and Tx respectively

  

#define ledR 13
#define ledV 12
#define ledA 11
char ch;
void setup() {
 pinMode(ledV,OUTPUT);
 pinMode(ledR,OUTPUT);
 pinMode(ledA,OUTPUT);
  
  Serial.begin(9600);
  myStream.begin(9600);
  digitalWrite(ledV,LOW);   
  digitalWrite(ledR,LOW);   
  digitalWrite(ledA,LOW); 
 
}

void loop() {
  
  while (myStream.available())    //if the Bluetooth client is available
  {
    ch = myStream.read();    //read data from stream
    
  }

  
        Serial.println(ch);
 if(ch=='a'){               
    digitalWrite(ledV,HIGH);        
    digitalWrite(ledR,LOW);       
    digitalWrite(ledA,LOW);
    Serial.println(ch);
}
 if(ch=='r'){                
    digitalWrite(ledR,HIGH);      
    digitalWrite(ledV,LOW);        
    digitalWrite(ledA,LOW);
     Serial.println(ch);
}
 if(ch=='d'){               
    digitalWrite(ledV,HIGH);       
    digitalWrite(ledR,LOW);       
    digitalWrite(ledA,HIGH);
     Serial.println(ch);
}
 if(ch=='i'){               
    digitalWrite(ledV,HIGH);       
    digitalWrite(ledR,LOW);       
    digitalWrite(ledA,HIGH);
     Serial.println(ch);
}
 if(ch=='f'){               
    digitalWrite(ledV,HIGH);       
    digitalWrite(ledR,HIGH);       
    digitalWrite(ledA,HIGH);
}
 if(ch=='x'){               
    digitalWrite(ledV,LOW);       
    digitalWrite(ledR,LOW);       
    digitalWrite(ledA,LOW);
     Serial.println(ch);
}

}
