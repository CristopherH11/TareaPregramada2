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
    float pagomensual;
    int tipo;
    int idsuperior;
    vector<Empleado *> empleados;
    Empleado* superior;

    public:

    ~Empleado();

    friend istream& operator >> (istream &i, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
    virtual void calcularPago() {};
    virtual float obtenerPago();
    virtual string obtenerNombre();
    virtual int obtenerTipo();
    virtual int obtenerId();
    virtual int obtenerIdSuperior();
    virtual void asignarSuperior(Empleado* empleado);
    virtual void insertarEmpleado(Empleado* empleado);
};


#endif