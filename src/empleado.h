#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>

using namespace std;

class Empleado {

    protected:

    int id;
    string nombre;
    string email;
    int pagomensual;
    vector<Empleado *> empleados;
    Empleado* superior;

    public:

    virtual ~Empleado();

    friend istream& operator >> (istream &o, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);
};


#endif