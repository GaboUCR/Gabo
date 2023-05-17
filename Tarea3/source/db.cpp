#include <fstream>
#include <sstream>
#include <vector>
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

int main () {

    leerArchivo("bebe");
    return 1;
}