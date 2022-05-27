#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(){


}

void EmpleadoNomina::calcularPago(){
    this->impuestos= this->costo*0.07;
    double pagoTotal= this->costo-this->impuestos;
    this->pagomensual= pagoTotal;

}