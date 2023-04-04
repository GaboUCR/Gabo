#include <iostream>
#include <list>
#include <string>
using namespace std;

class Edificio {

    private:
        bool ascensor;  
};

class EdificioDeAulas : public Edificio {

    private:
        bool soda;
        list<Aula> aulas;
    
    public:
        EdificioDeAulas (bool soda, list<Aula> aulas);
};

class Aula {

    private:
        int id;
        int pupitres;
        bool proyector;

    Aula (int id, int pupitres, bool proyector);
};

class Parqueo : public Edificio {
};

class Finca {

    private:
        bool bus_interno;
        list<Edificio> edificios; 
        string nombre;

    public:
        Finca(bool bus_interno, string nombre, list<Edificio> edificios);
};

class Campus {

    private:
        Finca fincas [5];
        int indice;

    public:
    
        Campus (Finca* fincas);
};