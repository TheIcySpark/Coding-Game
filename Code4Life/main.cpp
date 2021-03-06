#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct Molecula{
    int a = 0, b = 1, c = 2, d = 3, e = 4;
}MOLECULA;

struct Jugador{
    int j1 = 0, j2 = 1;
}JUGADOR;

struct Muestra{
    int id, descargada_por, rank, gain, puntaje, a, b, c, d, e;
    bool operator <(Muestra const & otro )const{
        return puntaje < otro.puntaje;
    }
}muestras[1002];

map <int, bool > muestras_procesadas;
queue <Muestra> muestras_descargadas;
queue <int> samples_descargados;
string modulo_actual[2];
int eta[2], puntaje[2];
int moleculas_almacenadas[2][5];
int experto_moleculas[2][5];
int moleculas_disponibles[5];
int numero_muestras;

void inicializacion(){
    int projectCount;
    cin >> projectCount;
    for (int i = 0; i < projectCount; i++) {
        int a;
        int b;
        int c;
        int d;
        int e;
        cin >> a >> b >> c >> d >> e;
    }
}

void actualizar_datos_muestras_descargadas(){
    int ids [3];
    int i = -1;
    while(!muestras_descargadas.empty()){
        ids[++i] = muestras_descargadas.front().id; muestras_descargadas.pop();
    }
    int id_actual = 0;
    for(int j = 0; j < numero_muestras; j++){
        if (muestras[j].id == ids[id_actual]){
            muestras_descargadas.push(muestras[j]);
            id_actual ++;
        }
        if(id_actual > i) break;
        if(j == numero_muestras - 1) j = -1;
    }
}

void lectura(){
    for (int i = 0; i < 2; i++) {
        cin >> modulo_actual[i] >> eta[i] >> puntaje[i];
        for(int j = 0; j < 5; j++) cin >> moleculas_almacenadas[i][j];
        for(int j = 0; j < 5; j++) cin >> experto_moleculas[i][j];
    }
    for(int i = 0; i < 5; i++) cin >> moleculas_disponibles[i];
    cin >> numero_muestras;
    for (int i = 0; i < numero_muestras; i++) {
        cin >> muestras[i].id >> muestras[i].descargada_por >> muestras[i].rank >> muestras[i].gain 
                >> muestras[i].puntaje >> muestras[i].a >> muestras[i].b >> muestras[i].c 
                >> muestras[i].d >> muestras[i].e;
        cerr << muestras[i].id <<'\n';
    }
    actualizar_datos_muestras_descargadas();
}


bool en_muestras_descargadas(Muestra muestra){
    Muestra m[3];
    int i = -1;
    while(!muestras_descargadas.empty()){
        m[++i] = muestras_descargadas.front(); muestras_descargadas.pop();
    }
    for(int j = 0; j <= i; j++) muestras_descargadas.push(m[j]);
    for(int j = 0; j <= i; j++) if (m[j].id == muestra.id) return true;
    return false;
}

void descargar_muestra(){
    int i;
    for(i = numero_muestras -1 ; i >= 0; i--){
        cerr<< muestras[i].id <<'\n';
        if (muestras[i].descargada_por == 0 and !muestras_procesadas[muestras[i].id] and
        !en_muestras_descargadas(muestras[i])) {
            muestras_procesadas[muestras[i].id] = true;
            muestras_descargadas.push(muestras[i]);
            cout << "CONNECT " << muestras[i].id;
            return;
        }else if (muestras[i].descargada_por == -1 and !muestras_procesadas[muestras[i].id]){
            muestras_procesadas[muestras[i].id] = true;
            muestras_descargadas.push(muestras[i]);
            cout << "CONNECT "<< muestras[i].id;
            return;
        }
    }
    cout<<"GOTO MOLECULES";
}

bool limite_moleculas_almacenadas_alcanzado(){
    int s = 0;
    for(int i = 0; i <5; i++) s += moleculas_almacenadas[JUGADOR.j1][i];
    return (s == 10) ? true : false;
}


int obtener_restas_muestras(Muestra m[], int pos, int molecula){
    int r = 0;
    if(molecula == MOLECULA.a) for(int i = 0; i < pos; i++) r += m[i].a;
    else if(molecula == MOLECULA.b) for(int i = 0; i < pos; i++) r += m[i].b;
    else if(molecula == MOLECULA.c) for(int i = 0; i < pos; i++) r += m[i].c;
    else if(molecula == MOLECULA.d) for(int i = 0; i < pos; i++) r += m[i].d;
    else if(molecula == MOLECULA.e) for(int i = 0; i < pos; i++) r += m[i].e;
    return r;
}

void tomar_particula(){
    Muestra m[3];
    int i = -1;
    while(!muestras_descargadas.empty()){
        m[++i] = muestras_descargadas.front(); muestras_descargadas.pop();
    }
    for(int j = 0; j <= i; j++) muestras_descargadas.push(m[j]);
    for(int j = 0; j <= i; j++){
        if(moleculas_almacenadas[JUGADOR.j1][MOLECULA.a] - obtener_restas_muestras(m, j, MOLECULA.a) 
        < m[j].a){
            cout << "CONNECT A";
            return;
        }
        if(moleculas_almacenadas[JUGADOR.j1][MOLECULA.b] - obtener_restas_muestras(m, j, MOLECULA.b) 
        < m[j].b){
            cout << "CONNECT B";
            return;
        }
        if(moleculas_almacenadas[JUGADOR.j1][MOLECULA.c] - obtener_restas_muestras(m, j, MOLECULA.c) 
        < m[j].c){
            cout << "CONNECT C";
            return;
        }
        if(moleculas_almacenadas[JUGADOR.j1][MOLECULA.d] - obtener_restas_muestras(m, j, MOLECULA.d) 
        < m[j].d){
            cout << "CONNECT D";
            return;
        }
        if(moleculas_almacenadas[JUGADOR.j1][MOLECULA.e] - obtener_restas_muestras(m, j, MOLECULA.e)
        < m[j].e){
            cout << "CONNECT E";
            return;
        }
    }
    cout << "GOTO LABORATORY";
}

bool posible_procesar_muestra(Muestra m){
    return (moleculas_almacenadas[JUGADOR.j1][MOLECULA.a] >= m.a and
    moleculas_almacenadas[JUGADOR.j1][MOLECULA.b] >= m.b and
    moleculas_almacenadas[JUGADOR.j1][MOLECULA.c] >= m.c and
    moleculas_almacenadas[JUGADOR.j1][MOLECULA.d] >= m.d and
    moleculas_almacenadas[JUGADOR.j1][MOLECULA.e] >= m.e);
}

void procesar_muestra(){
    if (posible_procesar_muestra(muestras_descargadas.front() )){
        Muestra m = muestras_descargadas.front(); muestras_descargadas.pop();
        samples_descargados.pop();
        cout << "CONNECT " << m.id;
    }else cout << "GOTO SAMPLES";
}

void analisis(){
    if (modulo_actual[JUGADOR.j1] == "START_POS") cout << "GOTO SAMPLES";
    else if(modulo_actual[JUGADOR.j1] == "SAMPLES"){
        if (samples_descargados.size() < 3 ){
            samples_descargados.push(2);
            cout<< "CONNECT 2";
        }else{
            cout<< "GOTO DIAGNOSIS";
        }
    }else if(modulo_actual[JUGADOR.j1] == "DIAGNOSIS"){
        if(muestras_descargadas.size() < 3){
            sort(muestras, muestras + numero_muestras - 1);
            descargar_muestra();
        }else cout<< "GOTO MOLECULES";
    }else if(modulo_actual[JUGADOR.j1] == "MOLECULES"){
        if(muestras_descargadas.empty()) "GOTO DIAGNOSIS";
        else if(limite_moleculas_almacenadas_alcanzado()) cout << "GOTO LABORATORY";
        else tomar_particula();
    }else if (modulo_actual[JUGADOR.j1] == "LABORATORY"){
        if(muestras_descargadas.empty()) "GOTO SAMPLES";
        procesar_muestra();
    }
    cout << '\n';
}

int main()
{
    inicializacion();
    while (true) {
        lectura();
        analisis();
    }
}