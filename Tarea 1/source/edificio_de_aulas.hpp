/**
 * @file EdificioDeAulas.h
 * @brief Definición de la clase EdificioDeAulas y sus métodos públicos.
 * @author Gabriel Gamboa
 * license BSD 3-Clause
 * Copyright (c) 2023 Gabriel Gamboa
 */

#ifndef EDIFICIO_DE_AULAS_H
#define EDIFICIO_DE_AULAS_H

#include "edificio.hpp"
#include "aula.hpp"
#include <list>

/**
 * @class EdificioDeAulas
 * @brief Clase que representa un edificio de aulas.
 */
class EdificioDeAulas : public Edificio {

private:
    bool soda; /**< Indica si el edificio cuenta con servicio de soda o no */
    std::list<Aula*> aulas; /**< Lista de aulas que pertenecen al edificio */

public:
    /**
     * @brief Constructor de la clase EdificioDeAulas.
     * @param ascensor Indica si el edificio cuenta con ascensor o no.
     * @param soda Indica si el edificio cuenta con servicio de soda o no.
     * @param aulas Lista de punteros a objetos Aula que pertenecen al edificio.
     */
    EdificioDeAulas(bool ascensor, bool soda, std::list<Aula*> aulas);

    /**
     * @brief Devuelve la lista de aulas que pertenecen al edificio.
     * @return Lista de punteros a objetos Aula que pertenecen al edificio.
     */
    std::list<Aula*> getAulas ();

    /**
     * @brief Imprime la información del edificio de aulas en la consola.
     */
    void imprimir();
};

#endif
