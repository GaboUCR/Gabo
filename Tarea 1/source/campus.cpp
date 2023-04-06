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

EdificioDeAulas::EdificioDeAulas(bool ascensor, bool soda, list<Aula> aulas)  {
    this->soda = soda;
    this->aulas = aulas;
    this->ascensor = ascensor;
}

Parqueo::Parqueo(bool ascensor) {
    this->ascensor = ascensor;
}

Finca::Finca(bool bus_interno, string nombre, list<Edificio> edificios) {
    this->bus_interno = bus_interno;
    this->nombre = nombre;
    this->edificios = edificios;
}

Campus::Campus(list<Finca> fincas) {
    this->fincas = fincas;
}

int main() {
  return 0;  
}

