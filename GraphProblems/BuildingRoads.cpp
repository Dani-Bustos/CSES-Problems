#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a ; i < b; i++) 
using namespace std;

int n ,m;
 

struct graph{
    vector<list<int>> adyacencias;
    vector<int> id;
    graph(int cant = 1){
        adyacencias.resize(cant);
        id.resize(cant,-1);
    }
    void addEdge(int v, int w){
        adyacencias[v].push_back(w);
        adyacencias[w].push_back(v);
    }

    vector<pair<int,int>> compConexas(){
        vector<pair<int,int>> res;

        int cantMarca = 0;
        
        fore(i,0,n){
            if(id[i] == -1){
                DFS(i,i);
                
                cantMarca++; 
            }
        }
        if(cantMarca == 1){return res;}
        int representante = 0;
        set<int> yaVistos;
        fore(i,0,n){
            if (id[i] != representante && yaVistos.find(id[i]) == yaVistos.end()){ 
                res.push_back({representante,id[i]});
                yaVistos.insert(representante);
                representante = id[i];
            }
        }
        return res;
    }
    void DFS(int root,int marca){
        id[root] = marca;
        for(int vecino : adyacencias[root]){
            if(id[vecino] == -1){
                DFS(vecino,marca);
            }
        }
    }

};
 
 
int main(){
    
    cin >> n >> m;
    
    graph G(n);
    int a ,b;
    fore(i,0,m){
        cin >> a >> b;
        G.addEdge(a-1,b-1);
    }
 
    vector<pair<int,int>> res = G.compConexas();
    cout << res.size() << "\n";
    fore(i,0,res.size()){
        cout << res[i].first + 1<< " " << res[i].second + 1 << "\n";
    }
 
 
 
}