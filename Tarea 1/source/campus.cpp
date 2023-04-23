 /**
 * license BSD 3-Clause
 * Copyright (c) 2023 Gabriel Gamboa
 */

#include <iostream>
#include "campus.hpp"

Campus::Campus(Finca* fincas[], int num_fincas, std::string nombre) {

    this->num_fincas = num_fincas;
    for(int i = 0; i < num_fincas; i++){
        this->fincas[i] = fincas[i];
    }
        this->nombre = nombre;
    }

void Campus::imprimir() {
    std::cout << "Campus: " << this->nombre << ", posee " << this->num_fincas << " fincas" << std::endl;

    for (int i = 0; i < this->num_fincas; i++) {
        std::cout << std::endl << std::endl << std::endl << "Finca " << i + 1 << ":" << std::endl;
        (this->fincas[i])->imprimir();
        std::cout << std::endl;
    }
}