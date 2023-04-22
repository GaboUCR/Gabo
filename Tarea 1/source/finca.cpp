#include <iostream>
#include "finca.hpp"

Finca::Finca(bool bus_interno, std::string nombre, std::list<Edificio*> edificios) {
this->bus_interno = bus_interno;
this->nombre = nombre;
this->edificios = edificios;
}

void Finca::imprimir() {

    std::cout << "Finca " << this->nombre << (bus_interno ? " (con bus interno)" : " (sin bus interno)") << std::endl;
    std::cout << " Posee " << this->edificios.size() << " edificios" << std::endl;

    int edificio_num = 1;
    for (auto it = this->edificios.begin(); it != this->edificios.end(); ++it) {
        std::cout << std::endl <<"  Edificio " << edificio_num << ":" << std::endl;
        if (auto aula = dynamic_cast<EdificioDeAulas*>(*it)) {
            aula->imprimir();
        } else if (auto parqueo = dynamic_cast<Parqueo*>(*it)) {
            parqueo->imprimir();
        }
        edificio_num++;
    }
    }

    std::string Finca::getNombre() {
        return this->nombre;
    }

    bool Finca::getBusInterno() {
        return this->bus_interno;
    }

    std::list<Edificio*> Finca::getEdificios() {
        return this->edificios;
    }

    