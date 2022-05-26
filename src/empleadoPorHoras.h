#ifndef EMPLEADOPORHORAS_H
#define EMPLEADOPORHORAS_H

#include "empleado.h"

using namespace std;

class EmpleadoPorHoras : public Empleado {


    public:
    EmpleadoPorHoras();
    virtual void calcularPago(int horas, float costo);

};

#endif