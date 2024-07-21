#include <MPXHZ6116A.h>

const int analogPin = A0; 

MPXHZ6116A pressureSensor(analogPin); 

void setup() {
  Serial.begin(9600);
}

void loop() {
  float compensatedPressure = pressureSensor.readPressureWithTempComp(25.0); 

  Serial.print("Compensated Pressure: ");
  Serial.print(compensatedPressure);
  Serial.println(" kPa");

  delay(2000);
}
