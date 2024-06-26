#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a ; i < b; i++) 
using namespace std;

int n ,m;
const int PAR = 2;
const int IMPAR = 1;

struct graph{
    vector<list<int>> adyacencias;
    vector<int> cantSubordinados;
    
    graph(int cant = 1){
        adyacencias.resize(cant);
        cantSubordinados.resize(cant,-1);
        
    }
    void addEdge(int v, int w){
        adyacencias[v].push_back(w);
        
    }
    
    int Subordinados(int raiz){
        if(cantSubordinados[raiz] != -1)  return cantSubordinados[raiz];
        int res = 0;
        for(int hijo: adyacencias[raiz]){
            res += 1 + Subordinados(hijo);
        }
        cantSubordinados[raiz] = res;
        return res;
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