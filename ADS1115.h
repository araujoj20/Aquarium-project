#ifndef ADS1115_H
#define ADS1115_H

#include <iostream>
#include <stdio.h>
#include <sys/types.h> // open
#include <sys/stat.h>  // open
#include <fcntl.h>     // open
#include <unistd.h>    // read/write usleep
#include <stdlib.h>    // exit
#include <inttypes.h>  // uint8_t, etc
#include <linux/i2c-dev.h> // I2C bus definitions
#include <sys/ioctl.h>

class ADS1115{

    private:
        int sensorValue;
        int fd;
    public:
        int openI2CBus(char *bus);
        int setI2CSlave(unsigned char deviceAddr);
        int readADS1115(int channel);
        int getSensorValue();

};

#endif