#include <iostream>
#include <list>
#include <string>
using namespace std;
#include "campus.hpp"

Aula::Aula(int id, int pupitres, bool proyector) {
    this->id = id;
    this->pupitres = pupitres;
    this->proyector = proyector; 
}

void Aula::Aula::imprimir () {

    if (this->proyector) {

        cout << "El aula " << this->id << ", posee "<< this->pupitres << " aulas y tiene proyector." << endl;
    }
    else {

        cout << "El aula " << this->id << ", posee "<< this->pupitres << " aulas y no tiene proyector." << endl;
    }
}

EdificioDeAulas::EdificioDeAulas(bool ascensor, bool soda, list<Aula> aulas) {
    this->soda = soda;
    this->aulas = aulas;
    this->ascensor = ascensor;
}

void EdificioDeAulas::EdificioDeAulas::imprimir() {

    for (auto it = (this->aulas).begin(); it != (this->aulas).end(); ++it) {
        it->imprimir();
    }    
}

Parqueo::Parqueo(bool ascensor) {
    this->ascensor = ascensor;
}

Finca::Finca(bool bus_interno, string nombre, list<Edificio*> edificios) {
    this->bus_interno = bus_interno;
    this->nombre = nombre;
    this->edificios = edificios;
}

void Finca::Finca::imprimir() {

    int aulas = 0;
    int parqueos = 0;

    for (auto it = (this->edificios).begin(); it != (this->edificios).end(); ++it) {
                
        if (auto aula = dynamic_cast<EdificioDeAulas*>(*it)) {
            // handle the Aula case
            aulas++;
        }
        // check if the current edificio is a Parqueo
        else if (auto parqueo = dynamic_cast<Parqueo*>(*it)) {
            // handle the Parqueo case
            parqueos++;
        }
            
    }    

    cout << "Finca "<< this->nombre <<"    Posee "<< (this->edificios).size() << " edificios, " << parqueos <<" son parqueos y " << aulas << " son aulas" << endl; 
}

string Finca::Finca::getNombre() {
    return this->nombre;
}

bool Finca::Finca::getBusInterno() {
    return this->bus_interno;
}

list<Edificio*> Finca::Finca::getEdificios() {
    return this->edificios;
}

Campus::Campus(list<Finca> fincas, string nombre) {
    this->fincas = fincas;
    this->nombre = nombre;
}

void Campus::Campus::imprimir() {

    cout <<"Campus: "<< this->nombre << ", posee " << (this->fincas).size()<<" fincas";

    auto it = (this->fincas).begin();

    for (int i=0; i<5; i++) {

        if (it == (this->fincas).end()) {
            break;
        }

        cout << ", finca " << it->getNombre();
        it++;
    }
    cout << endl;

    it = (this->fincas).begin();

    cout << "De estas fincas, por las que pasa el bus interno son: " << endl;

    for (int i=0; i<5; i++) {

        if (it == (this->fincas).end()) {
            break;
        }

        if (it->getBusInterno()) {
            cout << "- finca " << it->getNombre() << endl;
        }

        it++;
    }

    cout << endl <<"Informacion sobre las fincas: " << endl;

    for (auto it = (this->fincas).begin(); it != (this->fincas).end(); ++it) {

        it->imprimir();
    }

    cout << endl <<"Informacion sobre cada aula: " << endl;

    for (auto it_finca = (this->fincas).begin(); it_finca != (this->fincas).end(); ++it_finca) {

        cout << it_finca->getNombre() << ":" << endl;

        for (auto it_edificio = (it_finca->getEdificios()).begin(); it_edificio != (it_finca->getEdificios()).end(); ++it_edificio) {

            auto aula = dynamic_cast<EdificioDeAulas*>(*it_edificio);

            if (aula) { 
                (aula)->imprimir();
            }
            
        }            
    }    
}