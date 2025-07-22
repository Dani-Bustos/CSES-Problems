#include<bits/stdc++.h>

#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fore(i,a,b) for(int i = a; i < (int)b;i++)
#define LOG2(x) 31  - __builtin_clz(x)
using namespace std;
int n,q;
const int MAXN = 2*(1e5) +5;
const int EN_PROCESO = 2;
const int VISITADO = 1;
const int NO_VISITADO = 0;
int graph[MAXN];
vector<vector<int>> Rgraph(MAXN);
vector<int> depthCycle(MAXN);
vector<int> depthTree(MAXN,-1);
vector<int> idCycle(MAXN,-1);
unordered_map<int,int> cycleLength;
const int maxBitLength = 21;
int succesor[MAXN][maxBitLength];

pair<bool,int> marca_ciclos(int root,vector<int> &visited,int id,int depth){
   visited[root] = EN_PROCESO;
   depthCycle[root] = depth;
   
   int child = graph[root];
   if(root == child){
    idCycle[root] = id;
    cycleLength[id] = 1;
    visited[root] = VISITADO;
    return {false,-1};
   }
   if(visited[child] == VISITADO){
    visited[root] = VISITADO;
    return{false,-1};
    }
   else if(visited[child] == EN_PROCESO){
    idCycle[root] = id;
    visited[root] = VISITADO;
    cycleLength[id] = depthCycle[root] - depthCycle[child] + 1;
    return {true,child};
   }
    
   pair<bool,int> res = marca_ciclos(child,visited,id,depth+1);
   visited[root] = VISITADO;
   if(res.first){
    idCycle[root] = id;
    if(res.second != root){
        
        return {true,res.second};
    }
   
    }
  
    return{false,-1};
    
}
//Esta bfs se hace siempre en arboles
void BFS(int root,int depth){
    
    depthTree[root] = depth;
    for( int child : Rgraph[root]){
        //Eso es porque al principio, se ejecuta desde la raiz , que siempre pertenece a un ciclo
        if(idCycle[child] == -1){
            BFS(child,depth+1);
        }
    }
    
    
}



//Marcamos todos los nodos que estan en un ciclo
void prepareGraph(){
    vector<int> visited(n,NO_VISITADO);
    int marca = 0;
    fore(i,0,n){
        if(not visited[i]){
            marca_ciclos(i,visited,marca,0);
            marca++;
        }
    }
    fore(i,0,n){
        if(idCycle[i] != -1 && depthTree[i] == -1){
            BFS(i,0);
        }
    }
    //Precomputamos  bynary lifting
    for (int p = 1; p < maxBitLength; p++) {
        for (int i = 0; i <n; i++) {
            succesor[i][p] = succesor[succesor[i][p-1]][p-1];
       }
    }
}
int computeLift(int x,  int k){
        
   for (int i = 0; i < maxBitLength; i++) {
        if ((k >> i) & 1) {
            x = succesor[x][i];
        }
    }
    return x;
}



int main(){
    FAST_IO
    cin >> n;
    fore(i,0,n){
        cin >> graph[i];
        graph[i]--;
        Rgraph[graph[i]].push_back(i);
        succesor[i][0] = graph[i];
    }   
    
    prepareGraph();
    
    fore(from,0,n){
        int res = -1;
        
        if(graph[from] == from){
            res = 1;
        }
        else if( idCycle[from] != -1 ){ //Caso esta en un ciclo 
            res =cycleLength[idCycle[from]];
        }else{ //Caso esta en un arbol, calculamos la distancia a un ciclo y despues le sumamos la longitud
           int TreeRoot = computeLift(from,depthTree[from]);
           
           res = depthTree[from] + cycleLength[idCycle[TreeRoot]];
          
        
        }
        cout << res << " ";
    }

    return 0;
}