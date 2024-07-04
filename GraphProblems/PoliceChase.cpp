#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)
using namespace std;

const int INF = 1e9;
int N, M; //N:= Numero de remeras, M:= Cantidad de voluntarios 
//Vamos a trabajar directamente con la red residual
struct flow_digraph{
    vector<vector<int>> flujo;
    
    vector<vector<int>> adyacencias;
    vector<int> caminoAumento;
    vector<vector<int>> ogAdyacencias;
    
    
    //Nuestra fuente es el primero, el sumidero el ultimo
    flow_digraph(int cantVertices){
        adyacencias.resize(cantVertices,vector<int>(cantVertices));
        ogAdyacencias.resize(cantVertices,vector<int>(cantVertices));
       
        flujo.resize(cantVertices,vector<int>(cantVertices,0));
       
        
    }

    void addEdge(int v, int w){
        adyacencias[v][w] = 1;
        adyacencias[w][v] = 1;
        ogAdyacencias[v][w] = 1;
        ogAdyacencias[w][v] = 1;
        flujo[v][w] = 1;
        flujo[w][v] = 1;    

    
    }
    
    //Algoritmo de Edmond-Karps
    vector<pair<int,int>> maxFlow(){
        
        while(hasAugmenthPath()){
            int cuelloBotella = findBottleNeck();
            fore(i,0,caminoAumento.size()-1){
                //Subo el flujo de la arista si esta en el grafo
                
                flujo[caminoAumento[i]][caminoAumento[i+1]] -= cuelloBotella;
                
                //Bajo el flujo de la arista si no esta
                flujo[caminoAumento[i+1]][caminoAumento[i]] += cuelloBotella;
            }
        }
        
        
        
        return cutOutEdges();
    }

    vector<pair<int,int>> cutOutEdges(){
        queue<int> q; 
        vector<bool> visitados(adyacencias.size(),false);
    
        visitados[0] = true; q.push(0);
      
        int sumidero = adyacencias.size()-1;
        
        while(not q.empty()){
            int v = q.front(); q.pop();
            fore(i,0,adyacencias[v].size()){
            
                if(adyacencias[v][i] == 0)continue;
                //Si es una arista valida del residual el valor es distinto de 0
                if(not visitados[i] && flujo[v][i] != 0){
                
                
                    visitados[i] = true;
                    //Si ya llegamos al sumidero
                    
                    
                    q.push(i);
                }
            }
        }
        vector<pair<int,int>> res;
        fore(i,0,N){ 
            if(!visitados[i] ) continue; 
            fore(j,0,N){ 
                if(ogAdyacencias[i][j] && !visitados[j]) {
                    res.push_back({i,j});
                }
            }
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
            fore(i,0,adyacencias[v].size()){
            
                if(adyacencias[v][i] == 0)continue;
                //Si es una arista valida del residual el valor es distinto de 0
                if(not visitados[i] && flujo[v][i] != 0){
                
                    padre[i] = v;
                    visitados[i] = true;
                    //Si ya llegamos al sumidero
                    if(i == sumidero){
                        buildPath(padre,sumidero);
                        return true;
                    }
                    
                    q.push(i);
                }
            }
        }
        
        return false;
    }
    int findBottleNeck(){
        int neck = INF;
        fore(i,0,caminoAumento.size()-1){
            neck = min(neck,flujo[caminoAumento[i]][caminoAumento[i+1]]);
        }
        return neck;
    }
};

int main(){
    cin >> N >> M;
    flow_digraph G(N);
    fore(i,0,M){ int a,b;
        cin >> a >> b;
        G.addEdge(a-1,b-1);
    }
    vector<pair<int,int>> res = G.maxFlow();
    cout << res.size() << "\n";
    if(res.size() != 0){
        for(pair<int,int> a : res){
            cout << a.first + 1 <<" "<< a.second + 1 << "\n";
        }
    } 
    
    

}


