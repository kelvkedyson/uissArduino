/*
  Written by : Kelvin Kedyson Zacharia
  Tuesday - March 30, 2021
  BSC Telecommunications Engineering (UDSM - CoICT)
*/

#include "IRremote.h" //importing the library for the IR receiver

int receiver = 11; //setting the receiver pin at D11
int LED = 5; //using the D5 pin for LED

IRrecv irrecv(receiver); //creating an object of type IRrecv that has receiver functions
decode_results results; //decoding the results from the IR receiver

//function to translate the results and the circuit response
void translateIR(){
  
  Serial.print("Key Pressed : ");
  Serial.println(results.value, HEX); //printing in hexadecimal format

  //controlling by switching the values from the receiver results(decoded results)
  switch(results.value){
      case 0xFD00FF: 
        Serial.println("POWER ON"); //this is when the power on key is pressed
        powerON(); 
      break;
      case 0xFD40BF: 
        Serial.println("POWER OFF"); //this is when a power off key is pressed
        powerOFF();
       break;
       
      default:
        Serial.println("UNKNOWN KEY"); //this is when another key unspecified key is pressed
  }
}

void setup(){
  
  pinMode(LED, OUTPUT); //setting the LED as an output
  Serial.begin(9600); //initializing the serial monitor with 9600 baudrate
  irrecv.enableIRIn(); //starting the receiver
}

void loop(){
  //checking if the IR are received
  if(irrecv.decode(&results)){
    translateIR(); //calling the translator
    irrecv.resume(); //continue reading from the receiver
  }
}

//function to switch ON the LED
void powerON(){
  digitalWrite(LED, HIGH);
}

//function to switch OFF the LED
void powerOFF(){
  digitalWrite(LED, LOW);
}
