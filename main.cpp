#include <iostream>
#include "Sensors.h"
#include "TDS.h"
#include "PH.h"


int main() {

    TDS tds;
    PH ph;

    int rawValue1 = 25; // Valor de exemplo
    int rawValue2 = 60; // Valor de exemplo

    std::cout << "Valor TDS: " << tds.convertValue(rawValue1) << std::endl;
    std::cout << "Valor PH: " << ph.convertValue(rawValue2) << std::endl;
    std::cout << "Conversao para +1 e -1 : " << std::endl;
    std::cout << "Valor TDS: " << tds.getValue() << std::endl;
    std::cout << "Valor PH: " << ph.getValue() << std::endl;


    tds.readSensor();
    ph.readSensor();

    std::cout << "Valor TDS: " << tds.convertValue(tds.getValue()) << std::endl;
    std::cout << "Valor PH: " << ph.convertValue(ph.getValue()) << std::endl;

    return 0;
}