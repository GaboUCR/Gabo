#include <iostream>
#include "Calculadora.hpp"

int main() {
    Calculadora calc;  // Crear una instancia de la clase Calculadora

    double a = 5.0;
    double b = 3.0;

    // Probar el metodo suma
    std::cout << "La suma de " << a << " y " << b << " es: " << calc.suma(a, b) << "\n";

    // Probar el metodo resta
    std::cout << "La resta de " << a << " y " << b << " es: " << calc.resta(a, b) << "\n";

    // Probar el metodo multiplicacion
    std::cout << "La multiplicacion de " << a << " y " << b << " es: " << calc.multiplicacion(a, b) << "\n";

    // Probar el metodo division
    try {
        std::cout << "La division de " << a << " y " << b << " es: " << calc.division(a, b) << "\n";
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << "\n";  // Mostrar el mensaje de error
    }

    return 0;
}
