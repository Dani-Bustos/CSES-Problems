
    
 #include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)
using namespace std;

const int INF = 1e9;
int N, M; //N:= Numero de remeras, M:= Cantidad de voluntarios 
//Vamos a trabajar directamente con la red residual
struct flow_digraph{
    vector<vector<int>> rRes;
    
    vector<list<int>> adyacencias;
    vector<int> caminoAumento;
    
    
    //Nuestra fuente es el primero, el sumidero el ultimo
    flow_digraph(int cantVertices){
        adyacencias.resize(cantVertices);
        rRes.resize(cantVertices,vector<int>(cantVertices,0));
    }

    void addPair(int p1, int p2){
        //Estamos construyendo la red residual
        adyacencias[p1].push_back(p2);
        adyacencias[p2].push_back(p1);
    
        rRes[p1][p2] = 1;
        rRes[p2][p1] = 0;
        //Conectamos al source
        adyacencias[0].push_back(p1);
        adyacencias[p1].push_back(0);        
        
        rRes[p1][0] =0;
        rRes[0][p1]=1; 

        //Conectamos al sink
        int sink = adyacencias.size()-1;
        adyacencias[p2].push_back(sink);
        adyacencias[sink].push_back(p2);      
       
        rRes[sink][p2] =0 ;
        rRes[p2][sink] = 1; 

    
    }
    
    //Algoritmo de Edmond-Karps
    int maxFlow(){
        int flujo = 0;
        while(hasAugmenthPath()){
            int cuelloBotella = findBottleNeck();
            flujo+= cuelloBotella;
            fore(i,0,caminoAumento.size()-1){
                //Subo el rRes de la arista si esta en el grafo
                
                rRes[caminoAumento[i]][caminoAumento[i+1]] -= cuelloBotella;
               
                //Bajo el rRes de la arista si no esta
                rRes[caminoAumento[i+1]][caminoAumento[i]] += cuelloBotella;
            }
        }
        return flujo;
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
    
   
    vector<pair<int,int>> Parejas(){
         vector<vector<bool>> puestas(adyacencias.size(),vector<bool>(adyacencias.size(),false));
        vector<pair<int,int>> res;
        fore(i,1,N+1){
            for(int u : adyacencias[i]){
                if(u > i && rRes[u][i] == 1 && !puestas[i][u]){ 
                    res.push_back({i,u});
                    puestas[i][u] = true;
                }
            }
        }
        
        
        return res;
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
                if(not visitados[vecino] && rRes[v][vecino] != 0){
                
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
            neck = min(neck,rRes[caminoAumento[i]][caminoAumento[i+1]]);
        }
        return neck;
    }
};



int main(){
    
    
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   
    int k;
    cin >> N >> M >> k;

    int tamañoGrafo = N + M + 2;

    flow_digraph G(tamañoGrafo);
        
    fore(i,0,k){
        int a,b;
        cin >> a >> b;
        G.addPair(a,b + N);
            
    }
    int cant = G.maxFlow();
    
    vector<pair<int,int>> res =G.Parejas();
    cout << cant << "\n";
    for(pair<int,int> p : res){
        cout << p.first << " " << p.second - N   << "\n";
    }
    

}


