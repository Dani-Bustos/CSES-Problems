#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b;i++)
using namespace std;
typedef long long ll; const int INF = 1e9;



struct flow_digraph{
    
    vector<vector<int>> flujo;
    vector<vector<int>> capacidad;
    vector<list<int>> adyacencias;
    vector<list<int>> adyacenciasOG;
    vector<int> caminoAumento;
  
    //Nuestra fuente es el primero, el sumidero el ultimo
    flow_digraph(int cantVertices){
      
        adyacencias.resize(cantVertices);
        adyacenciasOG.resize(cantVertices);
        flujo.resize(cantVertices,vector<int>(cantVertices,0));
        capacidad.resize(cantVertices,vector<int>(cantVertices,0));
        
    }

    void addEdge(int v , int w, int cap){
        //Construimos el residual, añadimos de los dos lados
        adyacencias[v].push_back(w);
        adyacencias[w].push_back(v);    
        capacidad[v][w]  = cap;
        adyacenciasOG[v].push_back(w);
        
    }
    
    
    //Algoritmo de Edmond-Karps
    int maxFlow(){
        while(hasAugmenthPath()){
            int cuelloBotella = findBottleNeck();
            fore(i,0,caminoAumento.size()-1){
                //Subo el flujo de la arista si esta en el grafo
                flujo[caminoAumento[i]][caminoAumento[i+1]] += cuelloBotella;
                
                //Bajo el flujo de la arista si no esta
                flujo[caminoAumento[i+1]][caminoAumento[i]] -= cuelloBotella;
            }
        }
        return cutCapacity();
    }

    int cutCapacity(){
        int res = 0;
        for(int vecino: adyacencias[0]){
            res += flujo[0][vecino];
        }
        return res;
    }    
    //Ademas construimos este camino si existiese
    vector<int> buildPath(vector<int> &padre,int end){
        caminoAumento.clear();
        for(int v = end; v != 0; v = padre[v]){
            caminoAumento.push_back(v);
        }
        caminoAumento.push_back(0);
        reverse(caminoAumento.begin(),caminoAumento.end());
        
        return caminoAumento;
    }
    
    
    bool hasAugmenthPath(){
        queue<int> q; 
        vector<bool> visitados(adyacencias.size(),false);
        vector<int> padre(adyacencias.size(),-1);
        visitados[0] = true; q.push(0);
        padre[0] = 0;
        int sumidero = adyacencias.size()-1;
        
        while(not q.empty()){
            int v = q.front(); q.pop();
            for(int vecino  : adyacencias[v]){
            
                //Si es una arista valida del residual el valor es distinto de 0
                if(not visitados[vecino] && flujo[v][vecino] < capacidad[v][vecino]){
                
                    padre[vecino] = v;
                    visitados[vecino] = true;
                    //Si ya llegamos al sumidero
                    if(vecino == sumidero){
                        buildPath(padre,sumidero);
                        return true;
                    }
                    
                    q.push(vecino);
                }
            }
        }
        
        return false;
    }
    int findBottleNeck(){
        int neck = INF;
        fore(i,0,caminoAumento.size()-1){
            int p = caminoAumento[i];
            int v = caminoAumento[i+1];
            neck = min(neck,capacidad[p][v] - flujo[p][v]);
        }
        return neck;
    }

    vector<vector<int>> Paths(){ 
        vector<vector<int>> res;
        
        for(int v :adyacenciasOG[0]){
            vector<int> p;
            if(flujo[0][v] == 1){
                p = singlePath(0,adyacenciasOG.size()-1,p);
                if(p.size() != 0){
                    res.push_back(p);
                }
            }
        }
        return res;
    }
    
    vector<int> singlePath(int s,int t,vector<int> &p){
        p.push_back(s);    
        if (s == t){
            return p;
        }else{
            for(int u : adyacenciasOG[s]){
                if(flujo[s][u] == 1){
                    flujo[s][u]--;
                    
                    return singlePath(u,t,p);     
                }
            }
        }
        
    }
};



int main(){
    int n,m; 
    cin >> n >> m;
    flow_digraph G(n);
    fore(i,0,m){
        int a,b;
        cin >> a >> b;
        G.addEdge(a-1,b-1,1);
    }
    G.maxFlow();
    vector<vector<int>> caminos = G.Paths();
    cout << caminos.size() << "\n";
    if(caminos.size() != 0){
        
        
        fore(i,0,caminos.size()){
            cout << caminos[i].size() << "\n";
            fore(j,0,caminos[i].size()){
                cout << caminos[i][j] + 1  << " ";
            
            }
            cout << "\n";
        }
    }
}