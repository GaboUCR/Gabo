/**
 * @file Finca.h
 * @brief Definición de la clase Finca y sus métodos públicos.
 */

#ifndef FINCA_H
#define FINCA_H

#include "edificio_de_aulas.hpp"
#include "parqueo.hpp"
#include <list>
#include <string>

/**
 * @class Finca
 * @brief Clase que representa una finca.
 */
class Finca {

private:
    bool bus_interno; /**< Indica si la finca cuenta con servicio de bus interno o no */
    std::list<Edificio*> edificios; /**< Lista de edificios que pertenecen a la finca */
    std::string nombre; /**< Nombre de la finca */

public:
    /**
     * @brief Constructor de la clase Finca.
     * @param bus_interno Indica si la finca cuenta con servicio de bus interno o no.
     * @param nombre Nombre de la finca.
     * @param edificios Lista de punteros a objetos Edificio que pertenecen a la finca.
     */
    Finca(bool bus_interno, std::string nombre, std::list<Edificio*> edificios);

    /**
     * @brief Devuelve la lista de edificios que pertenecen a la finca.
     * @return Lista de punteros a objetos Edificio que pertenecen a la finca.
     */
    std::list<Edificio*> getEdificios();

    /**
     * @brief Devuelve si la finca cuenta con servicio de bus interno o no.
     * @return true si la finca cuenta con servicio de bus interno, false en caso contrario.
     */
    bool getBusInterno();

    /**
     * @brief Devuelve el nombre de la finca.
     * @return Nombre de la finca.
     */
    std::string getNombre();

    /**
     * @brief Imprime la información de la finca en la consola.
     */
    void imprimir();
};

#endif
