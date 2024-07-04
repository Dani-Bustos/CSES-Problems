#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a ; i < b; i++) 
using namespace std;

int n ,m;
const int PAR = 2;
const int IMPAR = 1;




struct graph{
    vector<list<int>> adyacencias;
    vector<int> tomados;
    vector<int> depth;
    
    graph(int cant = 1){
        adyacencias.resize(cant);
        cantSubordinados.resize(cant,-1);
        
    }
    void addEdge(int v, int w){
        adyacencias[v].push_back(w);
        
    }
    
    void Profundidad(int raiz,int nivel){
        
        depth[raiz] = nivel;
        for(int hijo : adyacencias[raiz]){
            depth[hijo] = depth[raiz] + 1;
            Profundidad(hijo,nivel+1);
        }
    }
    int Subordinados(int raiz){
        int res = -1;
        for(int hijo : adyacencias[raiz]){
            for(int hijo2 : adyacencias[raiz]){
                res = max(res,1 + Profundidad[hijo] + Profundidad[hijo2])
            }
        }
        
        i
        for
        
        for(int hijo: adyacencias[raiz]){

        }
    
    }
    
   
    
    
};
 
 
int main(){
    
    cin >> n;
    
    graph G(n);
    int a;
    fore(i,1,n){
        cin >> a;
        G.addEdge(a-1,i);
    }
 
    G.Subordinados(0);
    for(int x : G.cantSubordinados){
        cout << x << " ";
    }
   
    
 
 
}