/**
 * @file Campus.h
 * @brief Definición de la clase Campus y sus métodos públicos.
 * @author Gabriel Gamboa
 * license BSD 3-Clause
 * Copyright (c) 2023 Gabriel Gamboa
 */

#ifndef CAMPUS_H
#define CAMPUS_H

#include "finca.hpp"
#include <string>

/**
 * @class Campus
 * @brief Clase que representa un campus universitario.
 */
class Campus {

    private:
        Finca* fincas[5]; /**< Arreglo de fincas que pertenecen al campus */
        int num_fincas; /**< Número de fincas que pertenecen al campus */
        std::string nombre; /**< Nombre del campus */

    public:
        /**
         * @brief Constructor de la clase Campus.
         * @param fincas Arreglo de punteros a objetos Finca que pertenecen al campus.
         * @param num_fincas Número de fincas que pertenecen al campus.
         * @param nombre Nombre del campus.
         */
        Campus(Finca* fincas[], int num_fincas, std::string nombre);

        /**
         * @brief Imprime la información del campus en la consola.
         */
        void imprimir();
};

#endif
