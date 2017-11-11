#include <SPI.h>

const byte pHpin = A0;    // Connect the sensor's Po output to an analogue pin - whichever one you choose

// Variables:-
float Po;
float pH = 10;

void phSensor(){
  Po = (1023 - analogRead(pHpin));
  Serial.print(Po); //This is the raw voltage value for the pH module
   //Calibration values:
   //405@pH7
   //290@ph4

  Serial.print(", ph =");
  float pHm = map(Po, 290, 406, 400, 700); //maps voltage(Po) from calibration values at 4.00 and 7.00 pH
  float pH = (pHm/100);
  Serial.println(pH, 2); 
}