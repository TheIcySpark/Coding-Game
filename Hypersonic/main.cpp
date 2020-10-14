#include <iostream>
using namespace std;

struct Objeto{
    int propietario, x, y, parametro1, parametro2;
};

void lecturaInizializacion(int& f, int& c, int& MI_ID){
    cin >> f >> c >> MI_ID;
}

Objeto lecturaObjeto(){
    Objeto objeto;
    cin >> objeto.propietario >> objeto.x >> objeto.y >> objeto.parametro1 >> objeto.parametro2;
    return objeto;
}

void lecturaTurno(char& mapa[][], Objetos objetos[]){
    int cantidadObjetos;
    Objeto objetos[cantidadObjetos+1];
    for(int i = 1; i <= cantidadObjetos; i++)
        objetos[i]=lecturaObjeto();

    
}

int main(){
    int f, c, MI_ID;
    lecturaInizializacion(f, c, MI_ID);
    while(true){
        
    }

    return 0;
}