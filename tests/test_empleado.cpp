#include <gtest/gtest.h>
#include "../src/empleado.h"
#include "../src/empleadoNomina.h"
#include <string>

TEST(Test_Empleado, test_constructor){

    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    EmpleadoNomina *empleado = new EmpleadoNomina();
    streamStringsEntrada >> empleado;

    EmpleadoNomina *empleado2 = new EmpleadoNomina();

    empleado->asignarHoras(10);
    empleado->asignarCosto(65000);
    empleado->calcularPago();

    empleado->asignarSuperior(empleado2);

    int idActual = empleado->obtenerId();
    int idEsperada = 1;

    string nombreActual = empleado->obtenerNombre();
    string nombreEsperada = "Denis Tyler";

    int idSuperiorActual = empleado->obtenerIdSuperior();
    int idSuperiorEsperada = 1;

    double pagoActual = empleado->obtenerPago();
    double pagoEsperado = 60450;

    EXPECT_EQ(idActual, idEsperada);
    EXPECT_EQ(nombreActual, nombreEsperada);
    EXPECT_EQ(idSuperiorActual, idSuperiorEsperada);
    EXPECT_EQ(pagoActual, pagoEsperado);
}