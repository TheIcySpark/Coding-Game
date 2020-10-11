/// promedio de valores ascii de cadena redondeado a un decimal
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    string cadena;
    float promedio = 0;
    cin >> cadena;
    for(int i = 0; i < cadena.size(); i++){
        promedio += cadena[i];
    }
    cout << fixed << setprecision(1) << promedio / cadena.size();
}