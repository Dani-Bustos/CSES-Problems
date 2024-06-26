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
    
    vector<int> buildCycle(vector<int> &padres,int end){
        vector<int> res;
        res.push_back(end);
        for(int v = padres[end]; v != end; v = padres[v] ){
         res.push_back(v);   
        }
        res.push_back(end);
        //Como es un grafo el orden del ciclo es indistinto, no hace falta darlo vuelta
        return res;
    }
    
    vector<int> findCycle(){
        vector<bool> visited(n,false);
        vector<int> res;
        fore(i,0,n){
            //Sin la poda de las adyacencias da tle, ya que el llamado tiene un costo
            if(!visited[i] && adyacencias[i].size() != 0) res = DFS(i,visited);
            if (res.size()!= 0){
                return res;
            }
        }
        return res;
    }
    
    vector<int> DFS(int root,vector<bool> &visited){
         
        vector<int> padres(n,-1);
       
     
        padres[root] = root;
      
        stack<int> q; q.push(root);

        //DFS
        while(!q.empty()){
          int v = q.top();q.pop();
          if(visited[v]) continue;
          visited[v] = true;
          for(int vecino : adyacencias[v]){
            if(!visited[vecino]){
                
                padres[vecino] = v;
                
               
                q.push(vecino);
            }else if( padres[vecino] != v && padres[v] != vecino){
                padres[vecino] = v;
                return buildCycle(padres,vecino);
            } 
          }
        }
        vector<int> res;
        return res;
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
 
    vector<int> res = G.findCycle();
    if(res.size() == 0) cout << "IMPOSSIBLE";
    else{
        cout << res.size() << "\n";
    
    fore(i,0,res.size()){
        cout << res[i] + 1 << " ";
    }
    }
    
 
 
}