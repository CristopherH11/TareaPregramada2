#ifndef EMPLEADONOMINA_H
#define EMPLEADONOMINA_H

#include "empleado.h"

using namespace std;

class EmpleadoNomina : public Empleado {


    public:
    EmpleadoNomina();
    virtual void calcularPago(float costo);

};

#endif