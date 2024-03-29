/**
 * @file Edificio.h
 * @brief Definición de la clase Edificio y sus métodos públicos y protegidos.
  * @author Gabriel Gamboa
 * license BSD 3-Clause
 * Copyright (c) 2023 Gabriel Gamboa
 */

#ifndef EDIFICIO_H
#define EDIFICIO_H

/**
 * @class Edificio
 * @brief Clase abstracta que representa un edificio.
 */
class Edificio {

protected:
    bool ascensor; /**< Indica si el edificio cuenta con ascensor o no */

public:
    /**
     * @brief Destructor virtual de la clase Edificio.
     */
    virtual ~Edificio() {}

};

#endif
