#include <iostream>
using namespace std;

struct Pelota{
    int conteo_golpes, f, c;
};

Pelota pelotas[1000];
int alto, ancho, num_pelotas;
bool h_utilizados[1002][1002];
char mapa[1002][1002], caminos[1002][1002];

void lectura(){
    num_pelotas = 0;
    cin >> ancho >> alto;
    for(int i = 1; i <= alto; i++){
        for(int j = 1; j <= ancho; j++){
            cin >> mapa[i][j];
            if(mapa[i][j] >= '1' and mapa[i][j] <= '9'){
                pelotas[++num_pelotas].conteo_golpes = mapa[i][j] - '0';
                pelotas[num_pelotas].f = i;
                pelotas[num_pelotas].c = j;
            }
        }
    }
}

void inicializar(){
    for(int i = 1; i <= alto; i++){
        for(int j = 1; j <= ancho; j++){
            caminos[i][j] = '.';
        }
    }
}

void mostrar_camino(){
    for(int i = 1; i <= alto; i++){
        for(int j = 1; j <= ancho; j++){
            cout << caminos[i][j]<<h_utilizados[i][j];
        }
        cout << '\n';
    }
}

bool direccion_viable(int arriba, int derecha, Pelota pelota){
    while(pelota.conteo_golpes > 0){
        pelota.conteo_golpes -= 1;
        pelota.f += arriba;
        pelota.c += derecha;
        if(pelota.f < 0 or pelota.c < 0 or pelota.f > alto or pelota.c > ancho or 
        (mapa[pelota.f][pelota.c] == 'H' and pelota.conteo_golpes > 0) or
        (pelota.conteo_golpes == 0 and mapa[pelota.f][pelota.c] == 'X') or
        caminos[pelota.f][pelota.c] != '.' or
        (mapa[pelota.f][pelota.c] >= '0' and mapa[pelota.f][pelota.c] <= '9')){
            return false;
        }
    }
    return true;
}

Pelota marcar_camino(int arriba, int derecha, Pelota pelota, char simbolo){
    Pelota pelota_ret = pelota;
    while(pelota.conteo_golpes > 0){
        caminos[pelota.f][pelota.c] = simbolo;
        pelota.conteo_golpes -= 1;
        pelota.f += arriba;
        pelota.c += derecha;
    }
    pelota_ret.conteo_golpes -= 1;
    pelota_ret.c = pelota.c;
    pelota_ret.f = pelota.f;
    return pelota_ret;
}


bool backtracking(char direccion, int numero_pelota, Pelota pelota){
    int arriba = 0, derecha = 0;
    if(direccion == '^'){
        arriba = -1;
    }else if(direccion == '>'){
        derecha = 1;
    }else if(direccion == 'v'){
        arriba = 1;
    }else if(direccion == '<'){
        derecha = -1;
    }
    if(numero_pelota == 3){
        cout<<direccion_viable(arriba, derecha, pelota)<<'\n';
        mostrar_camino();
    }
    if(!direccion_viable(arriba, derecha, pelota)) return false;
    Pelota nueva_pelota = marcar_camino(arriba, derecha, pelota, direccion);
    if(mapa[nueva_pelota.f][nueva_pelota.c] == 'H'){
        if(!h_utilizados[nueva_pelota.f][nueva_pelota.c]){
            h_utilizados[nueva_pelota.f][nueva_pelota.c] = true;
            numero_pelota += 1;
        }else{
            marcar_camino(arriba, derecha, pelota, '.');
            return false;
        }
        if(numero_pelota > num_pelotas) return true;
    }else if(nueva_pelota.conteo_golpes == 0){
        marcar_camino(arriba, derecha, pelota, '.');
        return false;
    }
    if(backtracking('^', numero_pelota, pelotas[numero_pelota])) return true;
    if(backtracking('>', numero_pelota, pelotas[numero_pelota])) return true;
    if(backtracking('v', numero_pelota, pelotas[numero_pelota])) return true;
    if(backtracking('<', numero_pelota, pelotas[numero_pelota])) return true;
    h_utilizados[pelota.f][pelota.c] = false;
    marcar_camino(arriba, derecha, pelota, '.');
    return false;
}

void crear_camino(){
    if(backtracking('^', 1, pelotas[1])) return;
    if(backtracking('>', 1, pelotas[1])) return;
    if(backtracking('v', 1, pelotas[1])) return;
    if(backtracking('<', 1, pelotas[1])) return;
}


int main(){
    lectura();
    inicializar();
    crear_camino();
    mostrar_camino();
}