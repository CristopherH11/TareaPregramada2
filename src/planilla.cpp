#include "planilla.h"

using namespace std;

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
        this->indiceIds.insert(std::pair<int, Empleado*>(idNodo, jefe));
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

void Planilla::calcularSubtotal(){
    this->subTotal=0;
    for (Empleado *empleado : this->empleadosTotales){
        this->subTotal += empleado->obtenerPago();
    }
}

double Planilla::obtenerSubtotal(){
    return this->subTotal;
}

void Planilla::calcularImpuestos(){
    for (Empleado *empleado : this->empleadosTotales){
        this->impuestos += empleado->obtenerImpuestos();
    }
}

double Planilla::obtenerImpuestos(){
    return this->impuestos;
}

void Planilla::calcularTotal(){
    for (Empleado *empleado : this->empleadosTotales){
        this->total= this->impuestos + this->subTotal;
    }
}

double Planilla::obtenerTotal(){
    return this->total;
}

int Planilla::cantidadPlanilla(){
    return this->empleadosTotales.size();

}

istream& operator >> (istream &i, Planilla *planilla){
    string linea;

    while (std::getline(i, linea)) {
        string basura;
        int tipo;

        std::istringstream streamLinea(linea);
        streamLinea >> basura >> basura >> basura >> basura >> tipo >> basura;

        std::istringstream streamLinea2(linea);
        if (tipo==1){
            EmpleadoNomina *nuevoEmpleado = new EmpleadoNomina();
            streamLinea2 >> nuevoEmpleado;
            planilla->agregarEmpleado(nuevoEmpleado);
        }else {
            EmpleadoPorHoras *nuevoEmpleado = new EmpleadoPorHoras();
            streamLinea2 >> nuevoEmpleado;
            planilla->agregarEmpleado(nuevoEmpleado);
        }
    }

    return i;

}

ostream& operator << (ostream &o, const Planilla *planilla){
    for (Empleado *empleado : planilla->empleadosTotales){
        o << empleado << endl;
    }
    o << fixed;
    o << "El subtotal del reporte es: " << planilla->subTotal << endl;
    o << "Los impuestos a pagar del reporte son: " << planilla->impuestos << endl;
    o << "El total del reporte es: " << planilla->total << endl;

    return o;

}

istream& operator > (istream &i, Planilla *planilla){
    string linea;

    while (std::getline(i, linea)) {
        int id;
        float costo;

        Empleado* empleadoNuevo = planilla->indiceIds.at(id);
        empleadoNuevo->asignarCosto(costo);
        empleadoNuevo->calcularPago();
    }
    return i;
}

istream& operator < (istream &i, Planilla *planilla){
    string linea;

    while (std::getline(i, linea)) {
        int id;
        int horas;
        float costo;

        std::istringstream streamLinea(linea);
        streamLinea >> id >> costo >> horas;

        Empleado* empleadoNuevo = planilla->indiceIds.at(id);
        empleadoNuevo->asignarCosto(costo);
        empleadoNuevo->asignarHoras(horas);
        empleadoNuevo->calcularPago();
    }
    planilla->calcularSubtotal(); 
    planilla->calcularImpuestos();
    planilla->calcularTotal();
    return i;
}
