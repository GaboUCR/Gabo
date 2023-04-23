/**
 * @file Aula.h
 * @brief Definición de la clase Aula y sus métodos públicos.
 * @author Gabriel Gamboa
 * license BSD 3-Clause
 * Copyright (c) 2023 Gabriel Gamboa
 */

#ifndef AULA_H
#define AULA_H

#include <list>

/**
 * @class Aula
 * @brief Clase que representa un aula.
 */
class Aula {

    private:
        int id; /**< Identificador del aula */
        int pupitres; /**< Número de pupitres del aula */
        bool proyector; /**< Indica si el aula cuenta con un proyector o no */

    public:
        /**
         * @brief Constructor de la clase Aula.
         * @param id Identificador del aula.
         * @param pupitres Número de pupitres del aula.
         * @param proyector Indica si el aula cuenta con un proyector o no.
         */
        Aula(int id, int pupitres, bool proyector);

        /**
         * @brief Imprime la información del aula en la consola.
         */
        void imprimir();
};

#endif
