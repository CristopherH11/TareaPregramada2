#include <gtest/gtest.h>
#include "../src/empleadoPorHoras.h"


TEST(Test_EmpleadoPorHoras, Test_Agregar_Pago){

    EmpleadoPorHoras* nuevoEmpleado = new EmpleadoPorHoras(15, "Pedro", "Camacho", "hola@gmail.com");
    nuevoEmpleado->calcularPago(10.0, 20.3);

    float valorActual= nuevoEmpleado->obtenerPago();
    float valorEsperado=203;

    EXPECT_EQ(valorEsperado, valorActual);

}