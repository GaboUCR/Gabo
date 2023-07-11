#ifndef CALCULADORA_HPP
#define CALCULADORA_HPP

// Clase que representa una calculadora simple
class Calculadora {
public:
    // Constructor por defecto
    Calculadora() = default;

    // Metodos para realizar operaciones básicas
    double suma(double a, double b);  // Suma dos números
    double resta(double a, double b); // Resta dos números
    double multiplicacion(double a, double b); // Multiplica dos números
    double division(double a, double b); // Divide dos números
};

#endif // CALCULADORA_HPP
