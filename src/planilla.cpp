#include "planilla.h"


Planilla::Planilla(){
    Empleado *jefe= nullptr;

}
Planilla::~Planilla(){
    for (Empleado *empleado : this->empleadosTotales){
        delete empleado;
    } 
}

void Planilla::agregarEmpleado(Empleado* empleado){

    if (this->jefe==nullptr){
        this->jefe= empleado;
        empleado->asignarSuperior(empleado);
        int idNodo= empleado->obtenerId();
        this->indiceIds.insert(std::pair<int, Empleado*>(idNodo, jefe) );
        this->empleadosTotales.push_back(empleado);

    }else{
    
        Empleado* superior = this->indiceIds.at(empleado->obtenerIdSuperior());
        superior->insertarEmpleado(empleado);
        empleado->asignarSuperior(superior);
        int idNodo= empleado->obtenerId();
        this->indiceIds.insert(std::pair<int, Empleado*>(idNodo, empleado) );
        this->empleadosTotales.push_back(empleado);

    }
}

istream& operator >> (istream &i, Planilla *planilla){
    string linea;

    while (std::getline(i, linea)) {
        string basura;
        int tipo;

        std::istringstream streamLinea(linea);
        streamLinea >> basura >> basura >> basura >> basura >> tipo >> basura;

        if (tipo==1){
            EmpleadoNomina *nuevoEmpleado = new EmpleadoNomina();
            streamLinea >> nuevoEmpleado;
            planilla->agregarEmpleado(nuevoEmpleado);
        }else {
            EmpleadoPorHoras *nuevoEmpleado = new EmpleadoPorHoras();
            streamLinea >> nuevoEmpleado;
            planilla->agregarEmpleado(nuevoEmpleado);
        }
    }

    return i;

}

ostream& operator << (ostream &o, const Planilla *planilla){
    for (Empleado *empleado : planilla->empleadosTotales){
        o << empleado << endl;
    }

    return o;

}