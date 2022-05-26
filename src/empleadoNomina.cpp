#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(){


}

void EmpleadoNomina::calcularPago(float costo){
    float pagoTotal= costo-costo*0.07;
    this->pagomensual= pagoTotal;

}