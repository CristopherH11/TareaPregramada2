#include "empleado.h"

Empleado::~Empleado() {
    
}

double Empleado::obtenerPago(){

    return this->pagomensual;
}

double Empleado::obtenerImpuestos(){

    return this->impuestos;
}

string Empleado::obtenerNombre(){
    string nombreCompleto = this->nombre + " " + this->apellido;
    return nombreCompleto;
}

int Empleado::obtenerId(){
    return this->id;

}

int Empleado::obtenerIdSuperior(){
    return this->idsuperior;

}

void Empleado::asignarHoras(int horasNuevas){
    this->horas= horasNuevas;
}

void Empleado::asignarCosto(float costoNuevo){
    this->costo= costoNuevo;
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


    o << empleado->id << "," << empleado->nombre << " " << empleado->apellido << "," << empleado->superior->obtenerNombre() << "," << empleado->pagomensual;

    return o;
}