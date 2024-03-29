 /**
 * license BSD 3-Clause
 * Copyright (c) 2023 Gabriel Gamboa
 */

#include <iostream>
#include "parqueo.hpp"

Parqueo::Parqueo(bool ascensor) {
    this->ascensor = ascensor;
}

void Parqueo::imprimir() {
    std::cout << "Parqueo - ";
    std::cout << (ascensor ? "Tiene ascensor" : "No tiene ascensor") << std::endl;
}