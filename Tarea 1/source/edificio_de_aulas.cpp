 /**
 * license BSD 3-Clause
 * Copyright (c) 2023 Gabriel Gamboa
 */

#include <iostream>
#include "edificio_de_aulas.hpp"

EdificioDeAulas::EdificioDeAulas(bool ascensor, bool soda, std::list<Aula*> aulas) {
    this->soda = soda;
    this->aulas = aulas;
    this->ascensor = ascensor;
}

void EdificioDeAulas::imprimir() {
    std::cout << "Edificio de Aulas - ";
    std::cout << (ascensor ? "Tiene ascensor" : "No tiene ascensor") << ", ";
    std::cout << (soda ? "Tiene soda" : "No tiene soda") << std::endl;
    std::cout << "Posee las siguientes aulas: " << std::endl;

    for (auto it = this->aulas.begin(); it != this->aulas.end(); ++it) {
        (*it)->imprimir();
    }
}

std::list<Aula*> EdificioDeAulas::getAulas() {
    return this->aulas;
}
