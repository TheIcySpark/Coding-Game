#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Molecula{
    int a = 0, b = 1, c = 2, d = 3, e = 4;
}MOLECULA;

struct Jugador{
    int j1 = 0, j2 = 1;
}JUGADOR;

struct Muestra{
    int id, descargada_por, rank, gain, puntaje, a, b, c, d, e;
}muestras[1002];

string modulo_actual[2];
int eta[2], puntaje[2];
int moleculas_almacenadas[2][5];
int experto_moleculas[2][5];
int moleculas_disponibles[5];
int numero_muestras;

void inicializacion(){
    int projectCount;
    cin >> projectCount; cin.ignore();
    for (int i = 0; i < projectCount; i++) {
        int a;
        int b;
        int c;
        int d;
        int e;
        cin >> a >> b >> c >> d >> e; cin.ignore();
    }
}


void lectura(){
    for (int i = 0; i < 2; i++) {
        cin >> modulo_actual[i] >> eta[i] >> puntaje[i];
        for(int j = 0; j < 6; j++) cin >> moleculas_almacenadas[i][j];
        for(int j = 0; j < 6; j++) cin >> experto_moleculas[i][j];
    }
    for(int i; i < 6; i++) cin >> moleculas_disponibles[i];
    cin >> numero_muestras;
    for (int i = 0; i < numero_muestras; i++) {
        cin >> muestras[i].id >> muestras[i].descargada_por >> muestras[i].rank >> muestras[i].gain 
                >> muestras[i].puntaje >> muestras[i].a >> muestras[i].b >> muestras[i].c 
                >> muestras[i].d >> muestras[i].e;
    }
}

void analisis(){
    if(modulo_actual[JUGADOR.j1] == "DIAGNOSIS"){

    }else if(modulo_actual[JUGADOR.j1] == "MOLECULES"){

    }else if (modulo_actual[JUGADOR.j1] == "LABORATORY"){

    }
}

int main()
{
    inicializacion();
    while (true) {
        lectura();

        cout << "GOTO DIAGNOSIS" << endl;
    }
}