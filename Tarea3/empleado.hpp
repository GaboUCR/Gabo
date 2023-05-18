#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

using namespace std;

/** 
 * @brief Clase Empleado
 * 
 * Esta clase representa un empleado en una organización. Contiene detalles como 
 * nombre, correo, edad, departamento y salario.
 */
class Empleado {
private:
    string nombre; ///< Nombre del empleado
    string correo; ///< Correo electrónico del empleado
    int edad; ///< Edad del empleado
    string departamento; ///< Departamento en el que trabaja el empleado
    double salario; ///< Salario del empleado

public:
    /**
     * @brief Constructor de la clase Empleado
     * 
     * @param nombre Nombre del empleado
     * @param correo Correo electrónico del empleado
     * @param edad Edad del empleado
     * @param departamento Departamento en el que trabaja el empleado
     * @param salario Salario del empleado
     */
    Empleado(string nombre, string correo, int edad, string departamento, double salario);

    /** @brief Obtiene el nombre del empleado
     *  @return Nombre del empleado
     */
    string getNombre();

    /** @brief Establece el nombre del empleado
     *  @param nombre Nombre del empleado
     */
    void setNombre(string nombre);

    /** @brief Obtiene el correo electrónico del empleado
     *  @return Correo electrónico del empleado
     */
    string getCorreo();

    /** @brief Establece el correo electrónico del empleado
     *  @param correo Correo electrónico del empleado
     */
    void setCorreo(string correo);

    /** @brief Obtiene la edad del empleado
     *  @return Edad del empleado
     */
    int getEdad();

    /** @brief Establece la edad del empleado
     *  @param edad Edad del empleado
     */
    void setEdad(int edad);

    /** @brief Obtiene el departamento del empleado
     *  @return Departamento del empleado
     */
    string getDepartamento();

    /** @brief Establece el departamento del empleado
     *  @param departamento Departamento del empleado
     */
    void setDepartamento(string departamento);

    /** @brief Obtiene el salario del empleado
     *  @return Salario del empleado
     */
    double getSalario();

    /** @brief Establece el salario del empleado
     *  @param salario Salario del empleado
     */
    void setSalario(double salario);
};

#endif // EMPLEADO_HPP
