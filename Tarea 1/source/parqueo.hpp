/**
 * @file Parqueo.h
 * @brief Definición de la clase Parqueo y sus métodos públicos.
 */

#ifndef PARQUEO_H
#define PARQUEO_H

#include "edificio.hpp"

/**
 * @class Parqueo
 * @brief Clase que representa un parqueo.
 */
class Parqueo : public Edificio {

public:
    /**
     * @brief Constructor de la clase Parqueo.
     * @param ascensor Indica si el parqueo cuenta con ascensor o no.
     */
    Parqueo(bool ascensor);

    /**
     * @brief Imprime la información del parqueo en la consola.
     */
    void imprimir();
};

#endif
