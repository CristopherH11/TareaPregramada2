#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoPorHoras.h"
#include "planilla.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main (){
    Planilla *planilla = new Planilla();

    ifstream archivoPlanilla("personas.txt", std::ifstream::in);

    if (!archivoPlanilla.is_open()){
        cerr << "Error abriendo archivo categorias.txt" << endl;
        return -1;
    }
    
    archivoPlanilla >> planilla;

    archivoPlanilla.close();

    ifstream archivoPagosNomina("nomina.txt", std::ifstream::in);
    
    if (!archivoPagosNomina.is_open()){
        cerr << "Error abriendo archivo archivoPagosNomina.txt" << endl;
        return -1;
    }

    archivoPagosNomina > planilla;

    archivoPagosNomina.close();
    
    ifstream archivoPagosPorHoras("horastrabajadas.txt", std::ifstream::in);
    
    if (!archivoPagosPorHoras.is_open()){
        cerr << "Error abriendo archivo archivoPagosPorHoras.txt" << endl;
        return -1;
    }

    archivoPagosPorHoras < planilla;

    archivoPagosPorHoras.close();

    ofstream reporte("reporte.csv", std::ifstream::out);
    if (!reporte.is_open())
    {
        cerr << "Error abriendo archivo reporte.txt" << endl;
        return -1;
    }
    reporte << planilla;
    reporte.close();

    delete planilla;

}