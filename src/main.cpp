#include "empleado.h"
#include <iostream>
#include <sstream>

using namespace std;

int main (){

    string prueba = "1 Denis Tyler denis_tyler@biz.com 1 1";
    istringstream streamStringsEntrada(prueba);
    ostringstream streamStringsSalida {};
    Empleado *empleado = new Empleado();

    streamStringsEntrada >> empleado;
    streamStringsSalida << empleado;

    cout << streamStringsSalida.str();

    delete empleado;




}