#ifndef DB_HPP
#define DB_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include "empleado.hpp"
using namespace std;

vector<Empleado> leerArchivo(string nombreArchivo);
bool validarEntrada(string entrada, string patron);
vector<Empleado> buscarPorDepartamento(vector<Empleado> empleados, string departamento);
vector<Empleado> buscarPorSalario(vector<Empleado> empleados, double salarioMinimo, double salarioMaximo);

#endif // EMPLEADO_H