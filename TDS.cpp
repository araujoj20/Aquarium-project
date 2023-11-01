#include "TDS.h"

TDS::TDS()
{
    this->i2cChannel = 0;
}

TDS::~TDS()
{
}

float TDS::convertValue(int rawValue) {
        value = (float)(rawValue - 1);
        return value;
}