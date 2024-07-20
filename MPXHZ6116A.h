#ifndef MPXHZ6116A_H
#define MPXHZ6116A_H

#include <Arduino.h>

class MPXHZ6116A {
public:
  MPXHZ6116A(int analogPin, float supplyVoltage = 5.0);
  float readPressure();
  float readPressureWithTempComp(float temperature);

private:
  int _analogPin;
  float _supplyVoltage;
  float _tempMultiplier(float temperature);
};

#endif