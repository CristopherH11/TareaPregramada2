#include "empleado.h"

Empleado::~Empleado() {
    
}

float Empleado::obtenerPago(){

    return this->pagomensual;
}

string Empleado::obtenerNombre(){
    string nombreCompleto = this->nombre + " " + this->nombre;
    return nombreCompleto;
}

int Empleado::obtenerTipo(){
    return this->tipo;

}

int Empleado::obtenerId(){
    return this->id;

}

int Empleado::obtenerIdSuperior(){
    return this->idsuperior;

}

void Empleado::asignarSuperior(Empleado* nuevoSuperior){
    this->superior = nuevoSuperior;

}

void Empleado::insertarEmpleado(Empleado* empleado){
    this-> empleados.push_back(empleado);

}

istream& operator >> (istream &i, Empleado *empleado){
    i >> empleado->id >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipo >> empleado->idsuperior;
    return i;
}

ostream& operator << (ostream &o, const Empleado *empleado){
    o << empleado->id << "," << empleado->nombre << "," << empleado->apellido << "," << empleado->email << "," << empleado->tipo << "," << empleado->idsuperior;

    return o;
}