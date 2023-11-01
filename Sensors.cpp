#include "Sensors.h"

void Sensors::readSensor(){
    int buffTotal = 0;

    ads1115.openI2CBus(driver);
    ads1115.setI2CSlave(i2cAddress);
    ads1115.readADS1115(i2cChannel);
    value = ads1115.getSensorValue();

    /*
    if (i2cAddress == 0x40){
        for (int i = 0; i < BuffSize; i++)
            sensorBuffer[i] = i+1;
    }
    else if (i2cAddress == 0x10){
        for (int i = 0; i < BuffSize; i++)
            sensorBuffer[i] = i+3;
    }

    for (int i = 0; i < BuffSize; i++){
        buffTotal += sensorBuffer[i];
    }
    value = (float)buffTotal/(sizeof(sensorBuffer)/sizeof(sensorBuffer[0]));
    */
}

float Sensors::getValue() {
    return value;
}