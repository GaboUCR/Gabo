#include <fstream>
#include <iostream> 
#include <sstream>
#include <vector>
#include <regex>
#include <string>
#include "empleado.hpp"
#include <stdexcept>

vector<Empleado> leerArchivo(string nombreArchivo) {
    vector<Empleado> empleados;

    // Abre el archivo.
    ifstream archivo(nombreArchivo);

    // Verifica si el archivo se pudo abrir correctamente.
    if (!archivo) {
        throw std::invalid_argument("No existe el archivo");
    }

    // Lee cada línea del archivo.
    string linea;
    while (getline(archivo, linea)) {
        // Usa un stringstream para dividir la línea en campos separados por comas.
        stringstream ss(linea);
        string nombre, correo, departamento;
        int edad;
        double salario;

        // Lee cada campo de la línea.
        getline(ss, nombre, ',');
        getline(ss, correo, ',');
        ss >> edad;
        ss.ignore(1, ','); // Ignora la coma después de edad
        getline(ss, departamento, ',');
        ss >> salario;

        // Crea un nuevo objeto Empleado y lo agrega al vector.
        Empleado nuevoEmpleado(nombre, correo, edad, departamento, salario);
        empleados.push_back(nuevoEmpleado);
    }

    // Cierra el archivo.
    archivo.close();

    return empleados;
}

bool validarEntrada(string entrada, string patron) {
    std::regex patron_regex(patron);
    return std::regex_match(entrada, patron_regex);
}

vector<Empleado> buscarPorDepartamento(vector<Empleado> empleados, string departamento) {
    vector<Empleado> empleadosEnDepartamento;

    // Validar la entrada del usuario
    if (!validarEntrada(departamento, "^[a-zA-Z ]+$")) {
        std::cout << "Entrada de departamento inválida." << endl;
        return empleadosEnDepartamento;
    }

    for (Empleado empleado : empleados) {
        if (empleado.getDepartamento() == departamento) {
            empleadosEnDepartamento.push_back(empleado);
        }
    }

    return empleadosEnDepartamento;
}

vector<Empleado> buscarPorSalario(vector<Empleado> empleados, double salario) {
    vector<Empleado> empleadosConSalario;

    // Validar la entrada del usuario
    if (!validarEntrada(to_string(salario), "^\\$?[0-9]+(\\.[0-9]+)?$")) {
        cout << "Entrada de salario inválida." << endl;
        return empleadosConSalario;
    }

    for (Empleado empleado : empleados) {
        if (empleado.getSalario() == salario) {
            empleadosConSalario.push_back(empleado);
        }
    }

    return empleadosConSalario;
}

int main() {
    string nombreArchivo = "empleados.csv";

    vector<Empleado> empleados = leerArchivo(nombreArchivo);
    if (empleados.empty()) {
        cout << "No se encontraron empleados en el archivo." << endl;
        return 1;
    }

    cout << "Empleados leídos del archivo:" << endl;
    for (Empleado empleado : empleados) {
        cout << empleado.getNombre() << " - " << empleado.getDepartamento() << " - " << empleado.getSalario() << endl;
    }

    string departamento = "Tecnologia12";
    vector<Empleado> empleadosEnTecnologia = buscarPorDepartamento(empleados, departamento);
    cout << "\nEmpleados en el departamento de " << departamento << ":" << endl;
    for (Empleado empleado : empleadosEnTecnologia) {
        cout << empleado.getNombre() << endl;
    }

    return 0;
}