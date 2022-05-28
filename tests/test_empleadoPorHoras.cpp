#include <gtest/gtest.h>
#include "../src/empleadoPorHoras.h"
#include "../src/empleado.h"
#include <string>

TEST(Test_EmpleadoPorHoras, test_calcularPago){

    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    EmpleadoPorHoras *empleado = new EmpleadoPorHoras();
    streamStringsEntrada >> empleado;
    string prueba2 = "459 30.58 74";
    istringstream streamStringsEntrada2(prueba2);
    float costo;
    int id;
    int horas;
    streamStringsEntrada2 >> id >> costo >> horas;

    empleado->asignarCosto(costo);
    empleado->asignarHoras(horas);
    empleado->calcularPago();
    

    float actual = empleado->obtenerPago();
    float esperada = 2262.92;

    float actualImpuesto = empleado->obtenerImpuestos();
    float esperadaImpuesto = 0;

    EXPECT_FLOAT_EQ(actual, esperada);
    EXPECT_EQ(actualImpuesto, esperadaImpuesto);

}