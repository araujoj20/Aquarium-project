#ifndef SENSORS_H
#define SENSORS_H

#include <iostream>
#include "ADS1115.h"

#define BuffSize 6
#define driver "/dev/i2c-1"
#define i2cAddress 0x48

class Sensors {

private:
    float sensorBuffer[BuffSize];

protected:
    float value;
    int i2cChannel;

    ADS1115 ads1115;

public:

    void readSensor();

    float getValue();

};

#endif