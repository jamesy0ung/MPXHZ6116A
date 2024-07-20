#include "MPXHZ6116A.h"

MPXHZ6116A::MPXHZ6116A(int analogPin, float supplyVoltage)
  : _analogPin(analogPin), _supplyVoltage(supplyVoltage) {}

float MPXHZ6116A::readPressure() {
  int adcValue = analogRead(_analogPin);
  float voltage = (adcValue / 1023.0) * _supplyVoltage;
  float pressure = (((voltage / (_supplyVoltage * 0.008938)) + 0.09895) / 0.008938) / 100.0;
  return pressure;
}

float MPXHZ6116A::readPressureWithTempComp(float temperature) {
  float pressure = readPressure();
  float tm = _tempMultiplier(temperature);
  float error = (1.5 * tm * _supplyVoltage * 0.008938) / 100.0;
  return pressure + error;
}

float MPXHZ6116A::_tempMultiplier(float temperature) {
  if (temperature < 0) {
    return 2.85;
  } else if (temperature <= 85) {
    return 0.96;
  } else {
    return 1.66;
  }
}
