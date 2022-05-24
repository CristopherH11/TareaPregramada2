#include "empleadoPorHoras.h"

EmpleadoPorHoras::EmpleadoPorHoras(){


}

EmpleadoPorHoras::EmpleadoPorHoras(int id, string nombre, string apellido, string email){
    this->id= id;
    this->nombre= nombre + " " + apellido;
    this->email= email;
    this->pagomensual= 0;

}

void EmpleadoPorHoras::calcularPago(float horas, float costo){

    this->pagomensual= horas*costo;
}

float EmpleadoPorHoras::obtenerPago(){

    return this->pagomensual;
}