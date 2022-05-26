#include "empleadoPorHoras.h"

EmpleadoPorHoras::EmpleadoPorHoras(){


}

void EmpleadoPorHoras::calcularPago(int horas, float costo){
    float pagoTotal= horas * costo;
    this->pagomensual= pagoTotal;

}