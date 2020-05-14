#include <iostream>
using namespace std;
struct GLOBALES{
    int motos,necesarias;
    string l1,l2,l3,l4;
    string puente[5];
    void Inicializar(){
        puente[0]=l1;
        puente[1]=l2;
        puente[2]=l3;
        puente[3]=l4;
    }

    string SignificadoInstruccion(int instruccion){
        if(instruccion==1) return "SPEED";
        else if(instruccion==2) return "SLOW";
        else if(instruccion==3) return "JUMP";
        else if(instruccion==4) return "WAIT";
        else if(instruccion==5) return "UP";
        else if(instruccion==6) return "DOWN";
        else return "WAIT";
    }
};
GLOBALES global;
int listaInstrucciones[52];

struct MOTO{
    int x,y;
    bool activa;

    bool PosibleSubir(){
        if(y>0 or !activa) return true;
        else return false;
    }

    bool PosibleBajar(){
        if(y<3 or !activa) return true;
        else return false;
    }

    bool SinObstaculos(int ini,int fin,int y){
        fin=min(fin,int(global.l1.size()));
        for(;ini<=fin;ini++)
            if(global.puente[y][ini]=='0') return false;
        return true;
    }

    void Mover(int newX,int newY){
        if(!activa) return;
        x=newX;
        y=newY;
    }


};
struct MOTOS{
    MOTO moto[5];
    int velocidad;

    bool NecesariasActivas(){
        int cont=0;
        for(int i=1;i<=global.motos;i++) cont+=moto[i].activa;
        if(cont>=global.necesarias) return true;
        else return false;
    }

    bool PosibleSubir(){
        for(int i=1;i<=global.motos;i++)
            if(!moto[i].PosibleSubir()) return false;
        return true;
    }

    bool Subir(){
        if(!PosibleSubir()) return false;
        for(int i=1;i<=global.motos;i++){
            if(!moto[i].SinObstaculos(moto[i].x,moto[i].x+max(velocidad-1,0),moto[i].y) or
            !moto[i].SinObstaculos(moto[i].x+1,moto[i].x+velocidad,moto[i].y-1))
                moto[i].activa=false;
            moto[i].Mover(moto[i].x+velocidad,moto[i].y-1);
        }
        return true;
    }

    bool Bajar(){
        if(!PosibleBajar()) return false;
         for(int i=1;i<=global.motos;i++){
            if(!moto[i].SinObstaculos(moto[i].x,moto[i].x+max(velocidad-1,0),moto[i].y) or
            !moto[i].SinObstaculos(moto[i].x+1,moto[i].x+velocidad,moto[i].y+1))
                moto[i].activa=false;
            moto[i].Mover(moto[i].x+velocidad,moto[i].y+1);
        }
        return true;
    }

    bool PosibleBajar(){
        for(int i=1;i<=global.motos;i++)
            if(!moto[i].PosibleBajar()) return false;
        return true;
    }

    bool Acelerar(){
        velocidad+=1;
        for(int i=1;i<=global.motos;i++){
            if(!moto[i].SinObstaculos(moto[i].x,moto[i].x+velocidad,moto[i].y)) moto[i].activa=false;
            moto[i].Mover(moto[i].x+velocidad,moto[i].y);
        }
        return true;
    }

    bool Frenar(){
        if(velocidad==0) return false;
        velocidad-=1;
        for(int i=1;i<=global.motos;i++){
            if(!moto[i].SinObstaculos(moto[i].x,moto[i].x+velocidad,moto[i].y)) moto[i].activa=false;
            moto[i].Mover(moto[i].x+velocidad,moto[i].y);
        }
        return true;
    }

    bool Saltar(){
        if(velocidad==0) return false;
        for(int i=1;i<=global.motos;i++){
            if(!moto[i].SinObstaculos(moto[i].x,moto[i].x,moto[i].y) or
            !moto[i].SinObstaculos(moto[i].x+velocidad,moto[i].x+velocidad,moto[i].y))
                moto[i].activa=false;
            moto[i].Mover(moto[i].x+velocidad,moto[i].y);
        }
        return true;
    }

    bool Esperar(){
        if(velocidad==0) return false;
        for(int i=1;i<=global.motos;i++){
            if(!moto[i].SinObstaculos(moto[i].x,moto[i].x+velocidad,moto[i].y)) moto[i].activa=false;
            moto[i].Mover(moto[i].x+velocidad,moto[i].y);
        }
        return true;
    }


    bool Instruccion(int instruccion){
        if(instruccion==1) return Acelerar();
        else if(instruccion==2) return Frenar();
        else if(instruccion==3) return Saltar();
        else if(instruccion==4) return Esperar();
        else if(instruccion==5) return Subir();
        else if(instruccion==6) return Bajar();
    }

    int MaxAvanze(int turnos){
        return (((turnos+velocidad)*(turnos+velocidad+1))/2)-(((velocidad)*(velocidad+1))/2);
    }

    bool PosibleTerminar(int turnos){
        if (XActual()+MaxAvanze(turnos)>global.l1.size()) return true;
        else return false;
    }

    int XActual(){
        for(int i=1;i<=global.motos;i++){
            if(moto[i].activa) return moto[i].x;
        }
    }

};

MOTOS motos;


void LecturaInicial(){
    cin>>global.motos>>global.necesarias;
    cin>>global.l1>>global.l2>>global.l3>>global.l4;
    global.Inicializar();
}

void LecturaTurno(){
    cin>>motos.velocidad;
    for(int i=1;i<=global.motos;i++){
        cin>>motos.moto[i].x>>motos.moto[i].y>>motos.moto[i].activa;
    }
}


bool f(MOTOS motos,int turno){
    if(!motos.NecesariasActivas() or !motos.PosibleTerminar(50-turno)) return false;
    if(motos.XActual()>=global.l1.size()-1) return true;
    for(int i=1;i<=6;i++){
        MOTOS nuevasMotos=motos;
        listaInstrucciones[turno]=i;
        if(!nuevasMotos.Instruccion(i)) continue;

        if(f(nuevasMotos,turno+1)) return true;
    }
    return false;
}

int main()
{
    int i=1;
    bool primera=true;
    LecturaInicial();
    while(true){
        LecturaTurno();
        if(primera){
            primera=false;
            f(motos,1);
        }
        cout<<global.SignificadoInstruccion(listaInstrucciones[i++])<<endl;
    }

    return 0;
}
///xD
