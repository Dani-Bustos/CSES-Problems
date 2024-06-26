#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a ; i < b; i++) 
using namespace std;

int n ,m;
const int PAR = 2;
const int IMPAR = 1;

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
    
    vector<int> biparticion(){
         
        vector<int> biparticion(n,-1);
        fore(i,0,n){
            if(biparticion[i] == -1){
                BFS(i,biparticion);
                if(biparticion.size() == 0){
                    return biparticion;
                }
            }
        }
        return biparticion;
    }
    void BFS(int root, vector<int>&biparticion){
        vector<bool> visited(n,false); 
        vector<int> padres(n,-1);
       
        
        visited[root] = true;
        padres[root] = root;
        biparticion[root] = PAR;
        
        queue<int> q; q.push(root);

        
        while(!q.empty()){
          int v = q.front();q.pop();
          
          for(int vecino : adyacencias[v]){
            if(!visited[vecino]){
                visited[vecino] = true;
                padres[vecino] = v;
                biparticion[vecino] = (biparticion[v] == IMPAR ? PAR : IMPAR);
               
                q.push(vecino);
            }else if(biparticion[vecino] == biparticion[v]){
                biparticion.clear();
                
                return;
            }
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
 
    vector<int> res = G.biparticion();
    if(res.size() == 0) cout << "IMPOSSIBLE";
    else{

    
    fore(i,0,res.size()){
        cout << res[i] << " ";
    }
    }
    
 
 
}