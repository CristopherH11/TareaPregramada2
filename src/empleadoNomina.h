#ifndef EMPLEADONOMINA_H
#define EMPLEADONOMINA_H

#include "empleado.h"
#include <string>
#include <iostream>

class EmpleadoNomina : public Empleado {
    
    int horasTrabajadas;
    int costoPorHoras;
    
    public:
    EmpleadoNomina();
    EmpleadoNomina(int id, string nombre, string apellido, string email);

};


#endif