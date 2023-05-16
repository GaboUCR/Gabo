#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

using namespace std;

class Empleado {
private:
    string nombre;
    string correo;
    int edad;
    string departamento;
    double salario;

public:
    // Constructor
    Empleado(string nombre, string correo, int edad, string departamento, double salario);

    // Getters y Setters
    string getNombre();
    void setNombre(string nombre);

    string getCorreo();
    void setCorreo(string correo);

    int getEdad();
    void setEdad(int edad);

    string getDepartamento();
    void setDepartamento(string departamento);

    double getSalario();
    void setSalario(double salario);
};

#endif // EMPLEADO_HPP
