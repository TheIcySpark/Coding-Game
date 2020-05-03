#include <iostream>
#include <vector>
using namespace std;
#define NODOS 10000
int N;
vector<vector<int> > grafo(10002);
int memo[10002];

void Lectura(){
    int a,b;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a>>b;
        grafo[a].push_back(b);
    }
}

int F(int nodo){
    if(grafo[nodo].empty()) return 1;
    if(!memo[nodo]){
        for(int i=0;i<grafo[nodo].size();i++){
            memo[nodo]=max(memo[nodo],F(grafo[nodo][i])+1);
        }
    }
    return memo[nodo];
}

int main()
{
    int mayor=1;
    Lectura();
    for(int i=1;i<=NODOS;i++) mayor=max(mayor,F(i));
    cout<<mayor<<endl;

    return 0;
}
/**
8
1 2
1 3
3 4
2 4
2 5
10 11
10 1
10 3
**/
