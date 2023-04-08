#ifndef CAMPUS_H
#define CAMPUS_H

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Edificio {

protected:
    bool ascensor;

public:
    virtual ~Edificio() {}

};

class Aula {

private:
    int id;
    int pupitres;
    bool proyector;

public:
    Aula(int id, int pupitres, bool proyector);
    void imprimir();

};

class EdificioDeAulas : public Edificio {

private:
    bool soda;
    list<Aula*> aulas;

public:
    EdificioDeAulas(bool ascensor, bool soda, list<Aula*> aulas);
    list<Aula*> getAulas ();
    void imprimir();
};

class Parqueo : public Edificio {

public:
    Parqueo(bool ascensor);
};

class Finca {

private:
    bool bus_interno;
    list<Edificio*> edificios;
    string nombre;

public:
    Finca(bool bus_interno, string nombre, list<Edificio*> edificios);
    list<Edificio*> getEdificios();
    bool getBusInterno();
    string getNombre();
    void imprimir();
};

class Campus {

private:
    list<Finca*> fincas;
    string nombre;

public:
    Campus(list<Finca*> fincas, string nombre);
    void imprimir();
};

#endif
