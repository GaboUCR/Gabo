#include "Calculadora.hpp"
#include <iostream>

// Implementación de la función de suma
double Calculadora::suma(double a, double b) {
    return a + b;
}

// Implementación de la función de resta
double Calculadora::resta(double a, double b) {
    return a - b;
}

// Implementación de la función de multiplicación
double Calculadora::multiplicacion(double a, double b) {
    return a * b;
}

// Implementación de la función de división
double Calculadora::division(double a, double b) {
    if (b == 0) { // Comprobamos que el divisor no sea cero
        throw std::invalid_argument("¡Error! División por cero no está permitida.");
    }
    return a / b;
}
