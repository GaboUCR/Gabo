#include <iostream>
#include <list>
#include <string>
#include <random>
#include "campus.hpp"
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> edificio_count_dist(1, 5);
    uniform_int_distribution<> aula_count_dist(1, 5);
    uniform_int_distribution<> parqueo_count_dist(1, 3);
    uniform_int_distribution<> pupitres_dist(20, 40);
    bernoulli_distribution proyector_dist(0.5);
    bernoulli_distribution bus_interno_dist(0.5);
    bernoulli_distribution ascensor_dist(0.5);
    bernoulli_distribution soda_dist(0.5);

    Finca* fincas[5];

    int unique_aula_id = 1;

    for (int i = 0; i < 5; ++i) {
        string finca_name = to_string(i+1);

        Finca* finca;

        list<Edificio*> edificios;
        int edificio_count = edificio_count_dist(gen);

        for (int j = 1; j <= edificio_count; ++j) {
            list<Aula*> aulas;
            int aula_count = aula_count_dist(gen);

            for (int k = 1; k <= aula_count; ++k) {
                Aula* aula = new Aula(unique_aula_id++, pupitres_dist(gen), proyector_dist(gen)); 
                aulas.push_back(aula);
            }

            Edificio* edificioDeAulas = new EdificioDeAulas(ascensor_dist(gen), soda_dist(gen), aulas);
            edificios.push_back(edificioDeAulas);
        }

        int parqueo_count = parqueo_count_dist(gen);

        for (int j = 1; j <= parqueo_count; ++j) {
            Edificio* parqueo = new Parqueo(ascensor_dist(gen));
            edificios.push_back(parqueo);
        }

        finca = new Finca(bus_interno_dist(gen), finca_name, edificios);
        fincas[i] = finca;
    }

    Campus campus(fincas, 5, "My Campus");
    campus.imprimir();

    return 0;
    }
