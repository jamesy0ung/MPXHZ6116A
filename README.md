# MPXHZ6116A Arduino Library

This Arduino library provides a simple interface for the Freescale MPXHZ6116A absolute pressure sensor.

## Features

- Read pressure values (kPa) with and without temperature compensation.
- Easy-to-use API for quick integration.

## Installation

1. Download this library as a ZIP archive.
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library...**
3. Select the downloaded ZIP and click **Open**.

## Usage Example

```cpp
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
```

## Documentation

- **`MPXHZ6116A(int analogPin, float supplyVoltage = 5.0)`:** Constructor. `analogPin` is the sensor's output pin, `supplyVoltage` defaults to 5.0V.

- **`float readPressure()`:** Returns the pressure reading in kPa.

- **`float readPressureWithTempComp(float temperature)`:** Returns the pressure reading in kPa, compensated for temperature (in Celsius).

## License

This library is released under the GPLv3 License. See the `LICENSE` file for more details.
