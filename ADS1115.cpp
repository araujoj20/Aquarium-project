#include "ADS1115.h"




int ADS1115::openI2CBus(char *bus){
    if ((fd = open(bus, O_RDWR)) < 0) {
        printf("Error: Couldn't open device! %d\n", fd);
        exit (1);
    }else {
        printf("fd1: %d", fd);
    }
}

int ADS1115::setI2CSlave(unsigned char deviceAddr){
     printf("fd2: %d", fd);
    if (ioctl(fd, I2C_SLAVE, deviceAddr) < 0) {
        printf("Error: Couldn't find device on address!\n");
        exit (1);
    }
}

int ADS1115::readADS1115(int channel){
    
    uint8_t writeBuf[3];
    uint8_t readBuf[2];

    // set config register and start conversion
    // ANC1 and GND, 4.096v, 128s/s
    writeBuf[0] = 1;    // config register is 1

    switch (channel) {
        case 0:
            //configWriteBuff1 |= 0b01000000;
        writeBuf[1] = 0b11000011; 
            break;
        case 1:
            //configWriteBuff1 |= 0b01010000;
        writeBuf[1] = 0b11010011; 
            break;
        case 2:
            //configWriteBuff1 |= 0b01100000;
        writeBuf[1] = 0b11100011; 
            break;
        case 3:
            //configWriteBuff1 |= 0b01110000;
            writeBuf[1] = 0b11110011; 
        break;
        default:
            printf("Channel Incorrect\n");
    }

    //writeBuf[1] = 0b11010011; // bit 15-8 0xD3
    // bit 15 flag bit for single shot
    // Bits 14-12 input selection:
    // 100 ANC0; 101 ANC1; 110 ANC2; 111 ANC3
    // Bits 11-9 Amp gain. Default to 010 here 001 P19
    // Bit 8 Operational mode of the ADS1115.
    // 0 : Continuous conversion mode
    // 1 : Power-down single-shot mode (default)

    writeBuf[2] = 0b10000101; // bits 7-0  0x85
    // Bits 7-5 data rate default to 100 for 128SPS
    // Bits 4-0  comparator functions see spec sheet.

    // begin conversion
    if (write(fd, writeBuf, 3) != 3) {
    perror("Write to register 1");
    exit(-1);
    }

    // wait for conversion complete
    // checking bit 15
    do {
    if (read(fd, writeBuf, 2) != 2) {
        perror("Read conversion");
        exit(-1);
    }
    }
    while ((writeBuf[0] & 0x80) == 0);



    // read conversion register
    // write register pointer first
    readBuf[0] = 0;   // conversion register is 0
    if (write(fd, readBuf, 1) != 1) {
    perror("Write register select");
    exit(-1);
    }

    // read 2 bytes
    if (read(fd, readBuf, 2) != 2) {
    perror("Read conversion");
    exit(-1);
    }

    // convert display results
    int16_t val = readBuf[0] << 8 | readBuf[1];

    if (val < 0)   val = 0;

    sensorValue = val * 4.096 / 32768.0; // convert to voltage

    printf("Values: HEX 0x%02x DEC %d reading %4.3f volts.\n",
            val, val, sensorValue);
            
    close(fd);
    return 0;
}

int ADS1115::getSensorValue()
{
    return sensorValue;
}
