#include <iostream>
#include <map>
using namespace std;

struct Pelota{
    int conteo_golpes, x, y;
};
Pelota pelotas[1000];
int alto, ancho, num_pelotas;
bool h_utilizados[1002][1002];
char mapa[1002][1002], caminos[1002][1002];

void lectura(){
    cin >> ancho >> alto;
    for(int i = 1; i <= alto; i++){
        for(int j = 1; j <= ancho; j++){
            cin >> mapa[i][j];
            if(mapa[i][j] >= '1' and mapa[i][j] <= '9'){
                pelotas[++num_pelotas].conteo_golpes = mapa[i][j] - '0';
                pelotas[num_pelotas].x = j;
                pelotas[num_pelotas].y = i;
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

bool backtracking(char direccion, int numero_pelota, Pelota pelota){
    int arriba = 0, derecha = 0;
    if(direccion == '^'){
        arriba = 1;
    }else if(direccion == '>'){
        derecha = 1;
    }else if(direccion == 'v'){
        arriba = -1;
    }else if(direccion == '<'){
        derecha = -1;
    }
    
}

int main(){
    lectura();
    inicializar();
    backtracking('^', 1, pelotas[1]);
}