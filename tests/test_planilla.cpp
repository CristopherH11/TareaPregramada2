#include <gtest/gtest.h>
#include "../src/empleado.h"
#include "../src/empleadoPorHoras.h"
#include "../src/empleadoNomina.h"
#include "../src/planilla.h"
#include <string>

TEST(test_planilla, test_agregarEmpleado){
    Planilla *planilla = new Planilla();
    
    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    Empleado *empleado = new Empleado();
    streamStringsEntrada >> empleado;

    string prueba2 = "111 Alessandra Scott alessandra_scott@biz.com 1 53";
    istringstream streamStringsEntrada2(prueba);
    Empleado *empleado2 = new Empleado();
    streamStringsEntrada2 >> empleado2;

    string prueba3 = "322 Nathan Summers nathan_summers@biz.com 1 155";
    istringstream streamStringsEntrada3(prueba);
    Empleado *empleado3 = new Empleado();
    streamStringsEntrada3 >> empleado3;

    planilla->agregarEmpleado(empleado);
    planilla->agregarEmpleado(empleado2);
    planilla->agregarEmpleado(empleado3);

    int actual = planilla->cantidadPlanilla();
    int esperada = 3;

    EXPECT_EQ(actual, esperada);

}

TEST(test_planilla, test_calcularSubtotal){
    Planilla *planilla = new Planilla();

    float costo;
    int id;

    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    EmpleadoPorHoras *empleado = new EmpleadoPorHoras();
    streamStringsEntrada >> empleado;
    string prueba4 = "1 4600.98";
    istringstream streamStringsEntrada2(prueba4);
    streamStringsEntrada2 >> id >> costo;

    empleado->asignarCosto(costo);
    empleado->calcularPago();

    string prueba2 = "2 Clarissa Parker clarissa_parker@biz.com 1 1";
    istringstream streamStringsEntrada3(prueba2);
    EmpleadoNomina *empleado2 = new EmpleadoNomina();
    streamStringsEntrada3 >> empleado2;
    string prueba5 = "2 3097.50";
    istringstream streamStringsEntrada4(prueba5);
    streamStringsEntrada4 >> id >> costo;

    empleado2->asignarCosto(costo);
    empleado2->calcularPago();

    planilla->agregarEmpleado(empleado);
    planilla->agregarEmpleado(empleado2);

    planilla->calcularSubtotal();
    planilla->calcularImpuestos();
    planilla->calcularTotal();

    double actual = planilla->obtenerSubtotal();
    double esperada = 2880.675;

    EXPECT_FLOAT_EQ(actual, esperada);

}

TEST(test_planilla, test_calcularImpuestos){
    Planilla *planilla = new Planilla();

    float costo;
    int id;

    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    EmpleadoPorHoras *empleado = new EmpleadoPorHoras();
    streamStringsEntrada >> empleado;
    string prueba4 = "1 4600.98";
    istringstream streamStringsEntrada2(prueba4);
    streamStringsEntrada2 >> id >> costo;

    empleado->asignarCosto(costo);
    empleado->calcularPago();

    string prueba2 = "2 Clarissa Parker clarissa_parker@biz.com 1 1";
    istringstream streamStringsEntrada3(prueba2);
    EmpleadoNomina *empleado2 = new EmpleadoNomina();
    streamStringsEntrada3 >> empleado2;
    string prueba5 = "2 3097.50";
    istringstream streamStringsEntrada4(prueba5);
    streamStringsEntrada4 >> id >> costo;

    empleado2->asignarCosto(costo);
    empleado2->calcularPago();

    planilla->agregarEmpleado(empleado);
    planilla->agregarEmpleado(empleado2);

    planilla->calcularSubtotal();
    planilla->calcularImpuestos();
    planilla->calcularTotal();

    double actual = planilla->obtenerImpuestos();
    double esperada = 216.825;

    EXPECT_FLOAT_EQ(actual, esperada);

    
}

TEST(test_planilla, test_calcularTotal){
    Planilla *planilla = new Planilla();

    float costo;
    int id;

    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    EmpleadoPorHoras *empleado = new EmpleadoPorHoras();
    streamStringsEntrada >> empleado;
    string prueba4 = "1 4600.98";
    istringstream streamStringsEntrada2(prueba4);
    streamStringsEntrada2 >> id >> costo;

    empleado->asignarCosto(costo);
    empleado->calcularPago();

    string prueba2 = "2 Clarissa Parker clarissa_parker@biz.com 1 1";
    istringstream streamStringsEntrada3(prueba2);
    EmpleadoNomina *empleado2 = new EmpleadoNomina();
    streamStringsEntrada3 >> empleado2;
    string prueba5 = "2 3097.50";
    istringstream streamStringsEntrada4(prueba5);
    streamStringsEntrada4 >> id >> costo;

    empleado2->asignarCosto(costo);
    empleado2->calcularPago();

    planilla->agregarEmpleado(empleado);
    planilla->agregarEmpleado(empleado2);

    planilla->calcularSubtotal();
    planilla->calcularImpuestos();
    planilla->calcularTotal();

    double actual = planilla->obtenerTotal();
    double esperada = 3097.5;

    EXPECT_FLOAT_EQ(actual, esperada);

    
}

