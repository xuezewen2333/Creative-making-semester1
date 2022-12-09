#include <Servo.h>

//servo
Servo servo1; 

Servo servo2;

Servo servo3;

Servo servo4;

Servo servo5;

//servo 
int i = 0;
//sound
int soundSensor = A0 ;// // LM393 Sound Sensor Digital Pin D0 connected to pin 10
//led
int LedPins[ ] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
boolean LEDStatus=false;


void setup() {
//servo pin
  servo1.attach(A1);

  servo2.attach(A2); 

  servo3.attach(A3); 

  servo4.attach(A4); 

  servo5.attach(A5); 
//sound
pinMode (soundSensor, INPUT);
//led
int index;
for (index = 0; index <= 5; index++)
  {
    pinMode(LedPins[index], OUTPUT);
  }
Serial.begin(9600); //initialize serial


}


void loop() {
int SensorData=digitalRead(soundSensor); 
Serial.println(SensorData);//print the value
//Sound triggered servo motoring.
if (SensorData==1){
  //Controls the servo angle. 
  for (i = 0; i < 180; i++) { 

    servo1.write(i);              

    servo2.write(i);     

    servo3.write(i);

    servo4.write(i);

    servo5.write(i);         

    delay(3);  
  }

  for (i = 180; i > 0; i--) { 

    servo1.write(i);                

    servo2.write(i);     

    servo3.write(i);

    servo4.write(i);    

    servo5.write (i);     

    delay(3);                      
    }
}
  else{
    servo1.write(0);              

    servo2.write(0);     

    servo3.write(0);

    servo4.write(0);

    servo5.write(0); 
  }
if (SensorData==1) {
    if(LEDStatus==false){
        LEDStatus=true;
  digitalWrite(LedPins[1], HIGH);  //Turns on LED #0 (pin 4)
  digitalWrite(LedPins[2], HIGH);  //Turns on LED #1 (pin 5)
  digitalWrite(LedPins[3], HIGH);  //Turns on LED #2 (pin 6)
  digitalWrite(LedPins[4], HIGH);  //Turns on LED #3 (pin 7)
  digitalWrite(LedPins[5], HIGH);  //Turns on LED #4 (pin 8)
  digitalWrite(LedPins[6], HIGH);  //Turns on LED #5 (pin 9)
  digitalWrite(LedPins[7], HIGH);  //Turns on LED #0 (pin 4)
  digitalWrite(LedPins[8], HIGH);  //Turns on LED #1 (pin 5)
  digitalWrite(LedPins[9], HIGH);  //Turns on LED #2 (pin 6)
       
    }
    else if(LEDStatus==true){
        LEDStatus=false;
  digitalWrite(LedPins[1], LOW);   //Turn off LED #5 (pin 9)
  digitalWrite(LedPins[2], LOW);   //Turn off LED #4 (pin 8)
  digitalWrite(LedPins[3], LOW);   //Turn off LED #3 (pin 7)
  digitalWrite(LedPins[4], LOW);   //Turn off LED #2 (pin 6)
  digitalWrite(LedPins[5], LOW);   //Turn off LED #1 (pin 5)
  digitalWrite(LedPins[6], LOW);   //Turn off LED #0 (pin 4)
  digitalWrite(LedPins[7], LOW);   //Turn off LED #2 (pin 6)
  digitalWrite(LedPins[8], LOW);   //Turn off LED #1 (pin 5)
  digitalWrite(LedPins[9], LOW);   //Turn off LED #0 (pin 4)
    }}
}
