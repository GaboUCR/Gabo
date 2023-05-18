#include <fstream>
#include <iostream> 
#include <sstream>
#include <vector>
#include <regex>
#include <string>
#include "empleado.hpp"
#include "db.hpp"
#include <stdexcept>

vector<Empleado> leerArchivo(string nombreArchivo) {
    vector<Empleado> empleados;

    // Abre el archivo.
    ifstream archivo(nombreArchivo);

    // Verifica si el archivo se pudo abrir correctamente.
    if (!archivo) {
        throw std::invalid_argument("No existe el archivo");
    }

    // Expresiones regulares para validar los datos.
    string patronNombre = "^[a-zA-Z ]+$";
    string patronCorreo = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    string patronEdad = "^[0-9]+$";
    string patronDepartamento = "^[a-zA-Z ]+$";
    string patronSalario = "^[0-9]*\\.?[0-9]+$";

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

        // Verifica si los datos son válidos.
        if (!validarEntrada(nombre, patronNombre) || !validarEntrada(correo, patronCorreo) ||
            !validarEntrada(to_string(edad), patronEdad) || !validarEntrada(departamento, patronDepartamento) ||
            !validarEntrada(to_string(salario), patronSalario)) {
            continue; // Si algún dato no es válido, salta a la próxima iteración del bucle.
        }

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

vector<Empleado> buscarPorSalario(vector<Empleado> empleados, double salarioMinimo, double salarioMaximo) {
    vector<Empleado> empleadosConSalario;

    // Validar las entradas del usuario
    if (!validarEntrada(to_string(salarioMinimo), "^\\$?[0-9]+(\\.[0-9]+)?$") || 
        !validarEntrada(to_string(salarioMaximo), "^\\$?[0-9]+(\\.[0-9]+)?$")) {
        cout << "Entrada de salario inválida." << endl;
        return empleadosConSalario;
    }

    for (Empleado empleado : empleados) {
        double salario = empleado.getSalario();
        if (salario >= salarioMinimo && salario <= salarioMaximo) {
            empleadosConSalario.push_back(empleado);
        }
    }

    return empleadosConSalario;
}

int main() {
    // Se declara una variable "nombreArchivo" y se le asigna el valor "empleados.csv"
    string nombreArchivo = "empleados.csv";

    // Se declara un vector de empleados llamado "empleados" y se inicializa llamando a la función "leerArchivo" pasando el nombre del archivo como parámetro
    vector<Empleado> empleados = leerArchivo(nombreArchivo);

    // Se verifica si el vector de empleados está vacío
    if (empleados.empty()) {
        // Si está vacío, se muestra un mensaje de que no se encontraron empleados en el archivo
        cout << "No se encontraron empleados en el archivo." << endl;
        // Se retorna el valor 1 para indicar un error
        return 1;
    }

    // Se muestra un encabezado indicando que se van a imprimir los empleados leídos del archivo
    cout << "Empleados leídos del archivo:" << endl;

    // Se itera sobre cada objeto "Empleado" en el vector "empleados"
    for (Empleado empleado : empleados) {
        // Se imprime el nombre, departamento y salario de cada empleado
        cout << empleado.getNombre() << " - " << empleado.getDepartamento() << " - " << empleado.getSalario() << endl;
    }

    // Se declara una variable "departamento" y se le asigna el valor "Tecnologia"
    string departamento = "Tecnologia";

    // Se declara un nuevo vector de empleados llamado "empleadosEnTecnologia" y se llama a la función "buscarPorDepartamento" pasando el vector "empleados" y el departamento como parámetros
    vector<Empleado> empleadosEnTecnologia = buscarPorDepartamento(empleados, departamento);

    // Se muestra un encabezado indicando que se van a imprimir los empleados en el departamento especificado
    cout << "\nEmpleados en el departamento de " << departamento << ":" << endl;

    // Se itera sobre cada objeto "Empleado" en el vector "empleadosEnTecnologia"
    for (Empleado empleado : empleadosEnTecnologia) {
        // Se imprime el nombre de cada empleado en el departamento especificado
        cout << empleado.getNombre() << endl;
    }

    // Se declaran dos variables "salarioMinimo" y "salarioMaximo" y se les asigna un valor numérico
    double salarioMinimo = 5000;
    double salarioMaximo = 6000;

    // Se declara un nuevo vector de empleados llamado "empleadosEnRangoSalario" y se llama a la función "buscarPorSalario" pasando el vector "empleados", "salarioMinimo" y "salarioMaximo" como parámetros
    vector<Empleado> empleadosEnRangoSalario = buscarPorSalario(empleados, salarioMinimo, salarioMaximo);

    // Se muestra un encabezado indicando que se van a imprimir los empleados dentro del rango salarial especificado
    cout << "\nEmpleados con salario entre " << salarioMinimo << " y " << salarioMaximo << ":" << endl;
    // Se itera sobre cada objeto "Empleado" en el vector "empleadosEnRangoSalario"
    for (Empleado empleado : empleadosEnRangoSalario) {
        // Se imprime el nombre y salario de cada empleado dentro del rango especificado
        cout << empleado.getNombre() << " - " << empleado.getSalario() << endl;
    }
    
    return 0;
}