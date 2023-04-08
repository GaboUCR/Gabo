#include <iostream>
#include <list>
#include <string>
#include "campus.hpp"

using namespace std;

Aula::Aula(int id, int pupitres, bool proyector) {
    this->id = id;
    this->pupitres = pupitres;
    this->proyector = proyector;
}

void Aula::imprimir() {
    if (this->proyector) {
        cout << "El aula " << this->id << ", posee " << this->pupitres << " pupitres y tiene proyector." << endl;
    } else {
        cout << "El aula " << this->id << ", posee " << this->pupitres << " pupitres y no tiene proyector." << endl;
    }
}

EdificioDeAulas::EdificioDeAulas(bool ascensor, bool soda, list<Aula*> aulas) {
    this->soda = soda;
    this->aulas = aulas;
    this->ascensor = ascensor;
}

void EdificioDeAulas::imprimir() {
    for (auto it = this->aulas.begin(); it != this->aulas.end(); ++it) {
        (*it)->imprimir();
    }
}

list<Aula*> EdificioDeAulas::getAulas() {
    return this->aulas;
}

Parqueo::Parqueo(bool ascensor) {
    this->ascensor = ascensor;
}

Finca::Finca(bool bus_interno, string nombre, list<Edificio*> edificios) {
    this->bus_interno = bus_interno;
    this->nombre = nombre;
    this->edificios = edificios;
}

void Finca::imprimir() {
    int aulas = 0;
    int parqueos = 0;

    for (auto it = this->edificios.begin(); it != this->edificios.end(); ++it) {
        if (auto aula = dynamic_cast<EdificioDeAulas*>(*it)) {
            aulas++;
        } else if (auto parqueo = dynamic_cast<Parqueo*>(*it)) {
            parqueos++;
        }
    }

    cout << "Finca " << this->nombre << "    Posee " << this->edificios.size() << " edificios, " << parqueos << " son parqueos y " << aulas << " son aulas" << endl;
}

string Finca::getNombre() {
    return this->nombre;
}

bool Finca::getBusInterno() {
    return this->bus_interno;
}

list<Edificio*> Finca::getEdificios() {
    return this->edificios;
}

Campus::Campus(list<Finca*> fincas, string nombre) {
    this->fincas = fincas;
    this->nombre = nombre;
}
void Campus::imprimir() {

    cout <<"Campus: "<< this->nombre << ", posee " << (this->fincas).size()<<" fincas";

    auto it = (this->fincas).begin();

    for (int i=0; i<5; i++) {

        if (it == (this->fincas).end()) {
            break;
        }

        cout << ", finca " << (*it)->getNombre();
        it++;
    }
    cout << endl;

    it = (this->fincas).begin();

    cout << "De estas fincas, por las que pasa el bus interno son: " << endl;

    for (int i=0; i<5; i++) {

        if (it == (this->fincas).end()) {
            break;
        }

        if ((*it)->getBusInterno()) {
            cout << "- finca " << (*it)->getNombre() << endl;
        }

        it++;
    }

    cout << endl <<"Informacion sobre las fincas: " << endl;

    for (auto it = (this->fincas).begin(); it != (this->fincas).end(); ++it) {

        cout << endl;
        (*it)->imprimir();

        cout << endl << "Informacion sobre cada aula en la finca " << (*it)->getNombre() << ":" << endl;

        auto edificios = (*it)->getEdificios();
        for (auto it_edificio = edificios.begin(); it_edificio != edificios.end(); ++it_edificio) {
            auto edificio_de_aulas = dynamic_cast<EdificioDeAulas*>(*it_edificio);
            if (edificio_de_aulas != nullptr) {
                auto aulas = edificio_de_aulas->getAulas();
                for (auto it_aula = aulas.begin(); it_aula != aulas.end(); ++it_aula) {
                    (*it_aula)->imprimir();
                }
            }
        }
    }
}
