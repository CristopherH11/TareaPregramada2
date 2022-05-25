#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Empleado {

    protected:

    int id;
    string nombre;
    string apellido;
    string email;
    int pagomensual;
    int tipo;
    int idsuperior;
    vector<Empleado *> empleados;
    Empleado* superior;

    public:

    ~Empleado();

    friend istream& operator >> (istream &i, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
    void calcularPago();
    float obtenerPago();
    string obtenerNombre();
    int obtenerTipo();
    int obtenerIdSuperior();
};


#endif