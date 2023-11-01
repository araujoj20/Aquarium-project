#ifndef TDS_H
#define TDS_H

#include "Sensors.h"

class TDS : public Sensors
{
private:
    
public:
    TDS();
    ~TDS();

    float convertValue(int rawValue);
};




#endif
