#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoPorHoras.h"
#include "planilla.h"
#include <iostream>
#include <sstream>
#include <fstream>

int main (){
    Planilla *planilla = new Planilla();

    ifstream archivoPlanilla("personas.txt", std::ifstream::in);
    ofstream reporte("reporte.csv", std::ifstream::out);
    

    if (!archivoPlanilla.is_open()){
        std::cerr << "Error abriendo archivo categorias.txt" << std::endl;
        return -1;
    }

    archivoPlanilla >> planilla;

    if (!reporte.is_open())
    {
        std::cerr << "Error abriendo archivo reporteCatalogo.txt" << std::endl;
        return -1;
    }
    
    reporte << planilla;
    reporte.close();

    delete planilla;

}