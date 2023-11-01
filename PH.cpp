#include "PH.h"

PH::PH()
{
    this->i2cChannel = 1;
}

PH::~PH()
{
}

float PH::convertValue(int rawValue) {
        value = (float)(rawValue + 1);
        return value;
}