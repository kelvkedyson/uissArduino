#include "IRremote.h"
#include "Servo.h"

Servo servo;

int receiver = 11, servoPin = 10;
int greenLED = 7, redLED = 6, yellowLED = 8;

IRrecv irrecv(receiver);
decode_results results;

void setup(){
  
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  
  servo.attach(servoPin);
  irrecv.enableIRIn();
  
  Serial.begin(9600);
}

void loop(){
  if(irrecv.decode(&results)){
    translateIR();
    irrecv.resume();
  }
}

void translateIR(){
  
  Serial.print("Key Pressed : ");
  Serial.println(results.value, HEX);

  switch(results.value){
      case 0xFDA05F: 
        servo.write(0);
        Serial.println("0 degrees");
        switchOnGreenLED();
      break;
      case 0xFD10EF: 
        servo.write(90);
        Serial.println("90 degrees");
        switchOnYellowLED();
       break;
      case 0xFD50AF: 
        servo.write(180);
        Serial.println("180 degrees");
        switchOnRedLED();
      break;
       
      default:
        Serial.println("INVALID KEY");
  }
}

void switchOnGreenLED(){
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
}

void switchOnRedLED(){
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
}

void switchOnYellowLED(){
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
}
