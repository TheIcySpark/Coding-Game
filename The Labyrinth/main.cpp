#include <iostream>
#include <queue>
using namespace std;
struct COOR{
    int r,c,dis;
};
int movs[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int A;
///K es el personaje
COOR TAM,K,T,C;
char currentMap[102][202];
int mapOfDistances[102][202];
bool vis[102][202];
queue<COOR>Q;

///Leer datos de mapa y posicion actual
void Read(){
    ///Posicion actual del personaje
    cin>>K.r>>K.c;
    K.r+=1;
    K.c+=1;
    ///leer mapa actual
    for(int i=1;i<=TAM.r;i++){
        for(int j=1;j<=TAM.c;j++) cin>>currentMap[i][j];
    }
}

///Poner bordes con paredes para no desboradr
void Borders(){
    ///vertical
    for(int i=0;i<=TAM.r+1;i++) currentMap[i][0]=currentMap[i][TAM.c+1]='#';
    ///Horizontal
    for(int i=0;i<=TAM.c+1;i++) currentMap[0][i]=currentMap[TAM.r+1][i]='#';
}

///Reinicializa la matriz de visitados
void Clear(){
    for(int i=1;i<=TAM.r;i++){
        for(int j=1;j<=TAM.c;j++) vis[i][j]=0;
    }
}

///Genera distancias de el punto origen a los demas puntos disponibles
void Map(COOR originPoint){
    COOR currentPoint,newPoint;
    originPoint.dis=1;
    Q.push(originPoint);
    mapOfDistances[originPoint.r][originPoint.c]=originPoint.dis;
    vis[originPoint.r][originPoint.c]=true;
    while(!Q.empty()){
        currentPoint=Q.front(); Q.pop();
        if(currentMap[currentPoint.r][currentPoint.c]=='C'){
            C=currentPoint;
        }
        for(int i=0;i<4;i++){
            newPoint=currentPoint;
            newPoint.r+=movs[i][0];
            newPoint.c+=movs[i][1];
            if(currentMap[newPoint.r][newPoint.c]!='#' and !vis[newPoint.r][newPoint.c] and currentMap[newPoint.r][newPoint.c]!='?'){
                newPoint.dis++;
                Q.push(newPoint);
                mapOfDistances[newPoint.r][newPoint.c]=newPoint.dis;
                vis[newPoint.r][newPoint.c]=true;
            }
        }
    }
}

///Verifica si ya existe un camido valido de S a A
bool ValidPath(){
    if(C.r!=-1 and mapOfDistances[C.r][C.c]-1<=A) return true;
    else return false;
}


///Mueve en direccion a el punto mapeado
void Move(){
    int distance=mapOfDistances[K.r][K.c]-1;
    cerr<<distance;
    if(mapOfDistances[K.r-1][K.c]==distance) cout<<"UP"<<endl;
    else if(mapOfDistances[K.r][K.c+1]==distance) cout<<"RIGHT"<<endl;
    else if(mapOfDistances[K.r+1][K.c]==distance) cout<<"DOWN"<<endl;
    else if(mapOfDistances[K.r][K.c-1]==distance) cout<<"LEFT"<<endl;
}

///Busca una casilla desconocida alcanzable mas cercana
COOR SearchUnknown(){
    bool encontrado=false;
    COOR currentPoint,newPoint,unknownPoint;
    Q.push(K);
    while(!Q.empty()){
        currentPoint=Q.front(); Q.pop();
        for(int i=0;i<4;i++){
            newPoint=currentPoint;
            newPoint.r+=movs[i][0];
            newPoint.c+=movs[i][1];
            ///Ver si encontramos el punto deseando
            if(currentMap[newPoint.r][newPoint.c]=='?' and mapOfDistances[currentPoint.r][currentPoint.c]-1<=A){
                unknownPoint=currentPoint;
                encontrado=true;
                break;
            }
            if(currentMap[newPoint.r][newPoint.c]!='#' and currentMap[newPoint.r][newPoint.c]!='?' and !vis[newPoint.r][newPoint.c]){
                Q.push(newPoint);
                vis[newPoint.r][newPoint.c]=true;
            }
        }
        if(encontrado) break;
    }
    ///Vaciar cola
    while(!Q.empty()) Q.pop();
    return unknownPoint;
}

void ShowMap(){
    for(int i=1;i<=TAM.r;i++){
        for(int j=1;j<=TAM.c;j++) cerr<<currentMap[i][j]<<" ";
        cerr<<endl;
    }
}

void ShowDistances(){
    for(int i=1;i<=TAM.r;i++){
        for(int j=1;j<=TAM.c;j++) cerr<<mapOfDistances[i][j]<<" ";
        cerr<<endl;
    }
}

int main()
{
    bool init=false,alarmStart=false;
    ///Dimensiones y tiempo de alarma
    cin>>TAM.r>>TAM.c>>A;
    cerr<<TAM.r<<" "<<TAM.c<<" "<<A<<endl;
    Borders();
    while(1){
        ///Leer datos de mapa y posicion actual
        Read();
        ///Guardar valores iniciales
        if(!init){
            init=true;
            T=K;
            C.r=C.c=-1;
        }
        Clear();
        Map(T);
        if(ValidPath()){
            if(alarmStart){
                Clear();
                Map(T);
                ShowMap();
                ShowDistances();
                cerr<<K.r<<" "<<K.c<<endl;
                Move();
            }else{
                Clear();
                Map(C);
                if(mapOfDistances[K.r][K.c]==2) alarmStart=true;
                Move();
            }
        }else{
            ///Si no existe un camino ir a un punto que libere mas mapa
            Clear();
            COOR unknownPoint=SearchUnknown();
            Clear();
            Map(unknownPoint);
            Move();
        }
    }

    return 0;
}
