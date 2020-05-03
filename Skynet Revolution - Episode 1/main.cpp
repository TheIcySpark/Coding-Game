#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct ORIGIN_NODE{
    int minDis=1000,salidas,origen;
    const bool operator <(const ORIGIN_NODE &otro)const{
        if(salidas==otro.salidas) return minDis<otro.minDis;
        else return salidas>otro.salidas;
    }
};
struct BFS_NODE{
    int origen,pasos;
};
int N,L,E,pA;
vector<vector<int> >grafo(502);
BFS_NODE distancia[502];
queue<int>q;
bool puertaSalida[502];

void Inicializacion(){
    int n1,n2;
    cin>>N>>L>>E;
    for(int i=1;i<=L;i++){
        cin>>n1>>n2;
        n1+=1;
        n2+=1;
        grafo[n1].push_back(n2);
        grafo[n2].push_back(n1);
    }
    for(int i=1;i<=E;i++){
        cin>>n1;
        n1+=1;
        puertaSalida[n1]=true;
    }
}

int ObtenerOrigen(int node){
    while(distancia[node].origen!=node) node=distancia[node].origen;
    return node;
}

void EliminarEnlaze(int n1,int n2){
    for(int i=0;i<grafo[n1].size();i++){
        if(grafo[n1][i]==n2){
            grafo[n1].erase(grafo[n1].begin()+i);
            break;
        }
    }
}

void BFS(){
    bool vis[502];
    int pasos=0,actual;
    vector<ORIGIN_NODE> posibleCamino;
    ORIGIN_NODE nuevoOrigen;

    for(int i=0;i<grafo[pA].size();i++){
        distancia[grafo[pA][i]].origen=grafo[pA][i];
        nuevoOrigen.origen=grafo[pA][i];
        posibleCamino.push_back(nuevoOrigen);
    }

    q.push(pA);

    while(!q.empty()){
        actual=q.front(); q.pop();
        pasos+=1;
        for(int i=0;i<grafo[actual].size();i++){
            if(!vis[grafo[actual][i]]){
                vis[grafo[actual][i]]=true;
                distancia[grafo[actual][i]].origen=ObtenerOrigen(grafo[actual][i]);
                distancia[grafo[actual][i]].pasos=pasos;
                q.push(grafo[actual][i]);
            }
        }
    }


    for(int i=1;i<=N;i++){
        for(int j=0;j<posibleCamino.size();j++){
            if(posibleCamino[j].origen==distancia[i].origen){
                posibleCamino[j].salidas+=puertaSalida[i];
                posibleCamino[j].minDis=min(posibleCamino[j].minDis,distancia[i].pasos);
            }
        }
    }

    sort(posibleCamino.begin(),posibleCamino.end());
    EliminarEnlaze(pA,posibleCamino[0].origen);
    EliminarEnlaze(posibleCamino[0].origen,pA);
    cout<<pA-1<<" "<<posibleCamino[0].origen-1<<endl;
}

int main()
{
    Inicializacion();
    while(1){
        cin>>pA;
        pA+=1;
        BFS();
    }

    return 0;
}
