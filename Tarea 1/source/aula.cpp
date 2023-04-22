#include <iostream>
#include "aula.hpp"

Aula::Aula(int id, int pupitres, bool proyector) {
    this->id = id;
    this->pupitres = pupitres;
    this->proyector = proyector;
}

void Aula::imprimir() {
    if (this->proyector) {
        std::cout << "El aula " << this->id << ", posee " << this->pupitres << " pupitres y tiene proyector." << std::endl;
    } else {
        std::cout << "El aula " << this->id << ", posee " << this->pupitres << " pupitres y no tiene proyector." << std::endl;
    }
}
