#include <gtest/gtest.h>
#include "../src/empleado.h"
#include <string>

TEST(Test_Empleado, test_constructor){

    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    ostringstream streamStringsSalida {};
    Empleado *empleado = new Empleado();

    streamStringsEntrada >> empleado;

    int idSuperiorActual = empleado->obtenerIdSuperior();
    int idSuperiorEsperada = 1;

    EXPECT_EQ(idSuperiorActual, idSuperiorEsperada);
}