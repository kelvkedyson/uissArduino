#include "IRremote.h"

int receiver = 11;
int relay = 8;

IRrecv irrecv(receiver);
decode_results results;

void translateIR(){
  switch(results.value){
      case 0xFFA25D: 
        Serial.println("POWER ON");
        powerON(); 
      break;
      case 0xFFE21D: 
        Serial.println("POWER OFF"); 
        powerOFF();
       break;
       
      default:
        Serial.println("UNKNOWN KEY");
  }
}

void setup(){
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin(9600);
  irrecv.enableIRIn(); //starting the receiver
}

void loop(){
  //checking if the IR are received
  if(irrecv.decode(&results)){
    translateIR();
    irrecv.resume();
  }
}

void powerON(){
  digitalWrite(relay, LOW);
}

void powerOFF(){
  digitalWrite(relay, HIGH);
}
