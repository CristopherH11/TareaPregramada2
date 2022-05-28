#include <gtest/gtest.h>
#include "../src/empleadoNomina.h"
#include "../src/empleado.h"
#include <string>

TEST(Test_EmpleadoNomina, test_calcularPago){

    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    EmpleadoNomina *empleado = new EmpleadoNomina();
    streamStringsEntrada >> empleado;
    string prueba2 = "10 4753.90";
    istringstream streamStringsEntrada2(prueba2);
    float costo;
    int id;
    streamStringsEntrada2 >> id >> costo;

    empleado->asignarCosto(costo);
    empleado->calcularPago();
    

    float actual = empleado->obtenerPago();
    float esperada = 4421.127;

    float actualImpuesto = empleado->obtenerImpuestos();
    float esperadaImpuesto = costo*0.07;

    EXPECT_FLOAT_EQ(actual, esperada);
    EXPECT_EQ(actualImpuesto, esperadaImpuesto);

}