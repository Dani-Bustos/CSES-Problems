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
    vector<int> findPath(vector<int> &padres,int inicio,int final){
        vector<int> res; 
        for(int v = final; v != inicio; v = padres[v]){
            res.push_back(v);
        }
        res.push_back(inicio);
        reverse(res.begin(),res.end());
        return res;
    }
    vector<int> Targeted_BFS(int root,int target){
        vector<bool> visited(n,false); 
        vector<int> padres(n,-1);
        visited[root] = true;
        padres[root] = root;
        queue<int> q; q.push(root);
        while(!q.empty()){
          int v = q.front();q.pop();
          if( v == target){
            return findPath(padres,root,target);
          }
          for(int vecino : adyacencias[v]){
            if(!visited[vecino]){
                visited[vecino] = true;
                padres[vecino] = v;
                q.push(vecino);
            }
          }
        }
        vector<int> res; res.push_back(-1);
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
 
    vector<int> res = G.Targeted_BFS(0,n-1);
    if(res[0] == -1) cout << "IMPOSSIBLE";
    else{
    cout << res.size() << "\n";
    
    fore(i,0,res.size()){
        cout << res[i] + 1<< " ";
    }
    }
    
 
 
}