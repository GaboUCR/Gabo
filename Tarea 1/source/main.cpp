#include <iostream>
#include <list>
#include <string>
#include <random>
#include "campus.hpp"
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> edificio_count_dist(1, 20);
    uniform_int_distribution<> aula_id_dist(1, 100);
    uniform_int_distribution<> aula_count_dist(1, 30);
    uniform_int_distribution<> parqueo_count_dist(1, 200);
    uniform_int_distribution<> pupitres_dist(20, 40);
    bernoulli_distribution proyector_dist(0.5);
    bernoulli_distribution bus_interno_dist(0.5);


    list<Finca*> fincas;

    for (int i = 1; i <= 5; ++i) {
        string finca_name = to_string(i);

        list<Edificio*> edificios;
        int edificio_count = edificio_count_dist(gen);

        for (int j = 1; j <= edificio_count; ++j) {
            list<Aula*> aulas;
            int aula_count = aula_count_dist(gen);

            for (int k = 1; k <= aula_count; ++k) {
                Aula* aula = new Aula(aula_id_dist(gen), pupitres_dist(gen), proyector_dist(gen)); // Change to Aula*
                aulas.push_back(aula);
            }

            Edificio* edificioDeAulas = new EdificioDeAulas(true, true, aulas);
            edificios.push_back(edificioDeAulas);
        }

        int parqueo_count = parqueo_count_dist(gen);

        for (int j = 1; j <= parqueo_count; ++j) {
            Edificio* parqueo = new Parqueo(false);
            edificios.push_back(parqueo);
        }

        Finca* finca = new Finca(bus_interno_dist(gen), finca_name, edificios);
        fincas.push_back(finca);
    }

    Campus campus(fincas, "My Campus");
    campus.imprimir();

    return 0;
}

// #include <iostream>
// #include <list>
// #include <string>
// #include <ctime>
// using namespace std;
// #include "campus.hpp"

// EdificioDeAulas* crear_edificio_aula () {

//     // srand(time(nullptr));
//     list<Aula> aulas;

//     for(int i=0; i<2; i++) {
//         int random_number = std::rand() % 1000 + 1;
//         aulas.push_back(Aula(i, random_number, rand() % 2 == 1));

//     }

//     return new EdificioDeAulas(true, true, aulas);
// }

// Parqueo* crear_parqueo () {

//     return new Parqueo(rand() % 2 == 1);
// }


// int main () {

//     srand(time(nullptr));

//     Aula a = Aula(2, 10, true);
//     Aula b = Aula(3, 30, true);
//     list<Aula> my_list = {a,b};

//     EdificioDeAulas c = EdificioDeAulas(true, true, my_list);

//     Parqueo g = Parqueo(true);
//     Parqueo h = Parqueo(true);

//     list<Edificio*> edificios;

    
//     Finca fin = Finca(true, "1", edi);
//     Finca fin1 = Finca(false, "2", edi);
//     Finca fin2 = Finca(false, "3", edi);
//     Finca fin3 = Finca(true, "4", edi);
//     Finca fin4 = Finca(false, "5", edi);

//     list<Finca*> fincas;
//     list<Edificio*> edificios;


// }
//     for (int i =0; i<5; i++) {

        

//         for (int j =0; j <3; j++) {
//             edificios.push_front(crear_edificio_aula());
//             edificios.push_back(crear_parqueo());
//         }

//         Finca* fin = new Finca(rand() % 2 == 1, to_string(i), edificios);

//         fincas.push_back(fin);
//     }
   
//     Campus cam = Campus(fincas, "Rodrigo Facio");
//     cam.imprimir();
    


    

// }