/*
  Written by: Nelson Kimaro
  BSC Electronics Science and Communications (UDSM - CoICT)
  March 28, 2021
*/

int LDR = A0; //using analog pin A0 for LDR
int LED = 8; //using digital pin 8 for LED

//configuration codes (code that run only once)
void setup() {
  
  //initializing the serial monitor with 9600 baudrate
  Serial.begin(9600);

  //setting LDR analog pin as INPUT
  pinMode(LDR, INPUT);

  //setting LED digital pin as OUTPUT
  pinMode(LED, OUTPUT);
  
}

//all time running method (code that run repeatedly)
void loop() {
  
  float sensorValue = analogRead(LDR); //getting the values of the LDR from the analog pin whenever there is a change

  //printing the values on the serial monitor
  Serial.print("Sensor Value : ");
  Serial.println(sensorValue);

  //controlling the LED lighting
  if(sensorValue > 1000){
    digitalWrite(LED, HIGH); //switching ON the light
  }else{
    digitalWrite(LED, LOW); //switching OFF the light
  }
  
}
