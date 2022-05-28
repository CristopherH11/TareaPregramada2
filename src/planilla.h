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
    double subTotal;
    double impuestos;
    double total;
    vector<Empleado *> empleadosTotales;


    public:
    Planilla();
    ~Planilla();

    int cantidadPlanilla();
    void agregarEmpleado(Empleado* empleado);
    void calcularSubtotal();
    double obtenerSubtotal();
    void calcularImpuestos();
    double obtenerImpuestos();
    void calcularTotal();
    double obtenerTotal();

    friend istream& operator >> (istream &i, Planilla *planilla);
    friend ostream& operator << (ostream &o, const Planilla *planilla);
    friend istream& operator > (istream &i, Planilla *planilla);
    friend istream& operator < (istream &i, Planilla *planilla);
       
};



#endif