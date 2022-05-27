#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoPorHoras.h"
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Planilla {

    protected:
    Empleado *jefe;
    map<int, Empleado *> indiceIds;
    int subtotal;
    int impuestos;
    int total;
    vector<Empleado *> empleadosTotales;


    public:
    Planilla();
    ~Planilla();

    void agregarEmpleado(Empleado* empleado);

    friend istream& operator >> (istream &i, Planilla *planilla);
    friend ostream& operator << (ostream &o, const Planilla *planilla);
    friend istream& operator > (istream &i, Planilla *planilla);
    friend istream& operator < (istream &i, Planilla *planilla);
       
};



#endif