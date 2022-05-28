#include <gtest/gtest.h>
#include "../src/empleado.h"
#include "../src/empleadoPorHoras.h"
#include <string>

TEST(Test_Empleado, test_constructor){

    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    Empleado *empleado = new Empleado();
    streamStringsEntrada >> empleado;

    int idActual = empleado->obtenerId();
    int idEsperada = 1;

    string nombreActual = empleado->obtenerNombre();
    string nombreEsperada = "Denis Tyler";

    int idSuperiorActual = empleado->obtenerIdSuperior();
    int idSuperiorEsperada = 1;

    EXPECT_EQ(idActual, idEsperada);
    EXPECT_EQ(nombreActual, nombreEsperada);
    EXPECT_EQ(idSuperiorActual, idSuperiorEsperada);
}