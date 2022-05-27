#include "empleadoPorHoras.h"

EmpleadoPorHoras::EmpleadoPorHoras(){


}

void EmpleadoPorHoras::calcularPago(){
    double pagoTotal= this->costo*this->horas;
    this->impuestos= 0;
    this->pagomensual= pagoTotal;

}