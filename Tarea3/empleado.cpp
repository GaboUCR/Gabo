#include "Empleado.hpp"
using namespace std;

// Constructor
Empleado::Empleado(string nombre, string correo, int edad, string departamento, double salario) {
    this->nombre = nombre;
    this->correo = correo;
    this->edad = edad;
    this->departamento = departamento;
    this->salario = salario;
}

// Getters y Setters
string Empleado::getNombre() { return string(nombre); }
void Empleado::setNombre(string nombre) { this->nombre = string(nombre); }

string Empleado::getCorreo() { return string(correo); }
void Empleado::setCorreo(string correo) { this->correo = string(correo); }

int Empleado::getEdad() { return edad; }
void Empleado::setEdad(int edad) { this->edad = edad; }

string Empleado::getDepartamento() { return string(departamento); }
void Empleado::setDepartamento(string departamento) { this->departamento = string(departamento); }

double Empleado::getSalario() { return salario; }
void Empleado::setSalario(double salario) { this->salario = salario; }
