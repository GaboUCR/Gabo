#ifndef DB_HPP
#define DB_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include "empleado.hpp"
using namespace std;

/** 
 * @brief Lee el archivo de empleados.
 * 
 * Esta función lee un archivo y retorna una lista de empleados.
 * 
 * @param nombreArchivo El nombre del archivo a leer.
 * @return Vector de empleados.
 */
vector<Empleado> leerArchivo(string nombreArchivo);

/**
 * @brief Valida una entrada con base en un patrón.
 * 
 * Esta función toma una entrada y un patrón de regex, y verifica si la entrada coincide con el patrón.
 * 
 * @param entrada La cadena de entrada a validar.
 * @param patron El patrón de regex para validar la entrada.
 * @return true si la entrada es válida, false en caso contrario.
 */
bool validarEntrada(string entrada, string patron);

/** 
 * @brief Busca empleados por departamento.
 * 
 * Esta función busca y retorna empleados de un departamento específico.
 * 
 * @param empleados Vector de empleados para buscar.
 * @param departamento El nombre del departamento a buscar.
 * @return Vector de empleados en el departamento especificado.
 */
vector<Empleado> buscarPorDepartamento(vector<Empleado> empleados, string departamento);

/**
 * @brief Busca empleados por salario.
 * 
 * Esta función busca y retorna empleados dentro de un rango de salario específico.
 * 
 * @param empleados Vector de empleados para buscar.
 * @param salarioMinimo El salario mínimo del rango de búsqueda.
 * @param salarioMaximo El salario máximo del rango de búsqueda.
 * @return Vector de empleados dentro del rango de salario especificado.
 */
vector<Empleado> buscarPorSalario(vector<Empleado> empleados, double salarioMinimo, double salarioMaximo);

#endif // DB_HPP
