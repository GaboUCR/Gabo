#include <iostream>
#include <list>
using namespace std;

class Edificio {

    private:
        bool ascensor;

};

class EdificioDeAulas : public Edificio {

    private:
        bool soda;
        list<Aula> aulas;

};

class Aula {

    private:
        int id;
        int pupitres;
        bool proyector;
};

class Parqueo : public Edificio {


};

class Finca {

    private:
        bool bus_interno;
        list<Edificio> edificios; 

};

class Campus {

    private:
        Finca fincas [5];

};