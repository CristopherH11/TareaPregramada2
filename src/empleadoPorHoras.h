#ifndef EMPLEADOPORHORAS_H
#define EMPLEADOPORHORAS_H

#include "empleado.h"
#include <string>
#include <iostream>

class EmpleadoPorHoras : public Empleado {


    public:
    EmpleadoPorHoras();
    EmpleadoPorHoras(int id, string nombre, string apellido, string email);
    void calcularPago(float horas, float costo);
    int obtenerPago();

};


#endif