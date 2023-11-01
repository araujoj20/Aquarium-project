#ifndef PH_H
#define PH_H

#include "Sensors.h"

class PH : public Sensors
{
private:
    
public:
    PH();
    ~PH();

    float convertValue(int rawValue);
};




#endif
