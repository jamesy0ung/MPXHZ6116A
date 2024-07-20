#include <MPXHZ6116A.h>

#define SENSOR_PIN A0
#define SUPPLY_VOLTAGE 5.0

MPXHZ6116A pressureSensor(SENSOR_PIN, SUPPLY_VOLTAGE);

void setup() {
  Serial.begin(9600);
  Serial.println("MPXHZ6116A Pressure Sensor Example");
}

void loop() {
  float pressure = pressureSensor.readPressure();
  Serial.print("Pressure: ");
  Serial.print(pressure, 2);
  Serial.print(" kPa (");
  Serial.print(pressure * 10, 2);
  Serial.println(" hPa)");

  float compensatedPressure = pressureSensor.readPressureWithTempComp(25.0);
  Serial.print("Compensated Pressure: ");
  Serial.print(compensatedPressure, 2);
  Serial.print(" kPa (");
  Serial.print(compensatedPressure * 10, 2);
  Serial.println(" hPa)");

  delay(1000);
}