
    
 #include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)
using namespace std;

const int INF = 1e9;
int N, M; //N:= Numero de remeras, M:= Cantidad de voluntarios 
//Vamos a trabajar directamente con la red residual

struct flow_digraph{
    vector<vector<int>> rRes;
    vector<list<int>> ogAdy;
    vector<list<int>> adyacencias;
    vector<int> caminoAumento;
    
    
    //Nuestra fuente es el primero, el sumidero el ultimo
    flow_digraph(int cantVertices){
        adyacencias.resize(cantVertices);
        rRes.resize(cantVertices,vector<int>(cantVertices,0));
        ogAdy.resize(cantVertices);
    }

    void addPair(int p1, int p2){
        //Estamos construyendo la red residual
        adyacencias[p1].push_back(p2);
        adyacencias[p2].push_back(p1);
        ogAdy[p1].push_back(p2);
        rRes[p1][p2] = 1;
        rRes[p2][p1] = 0;
        
    
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
    
   
    vector<string> D_paths(int Pamount){
       vector<string> paths; 
       vector<vector<bool>> tomadas(adyacencias.size(),vector<bool>(adyacencias.size(),false));

        for(int u : adyacencias[0]){
            //Los caminos se indexan desde 1
            if(rRes[u][0] == 1 && !tomadas[0][u]){
                tomadas[0][u] = true;
                paths.push_back("1" + T_DFS(u,tomadas));

            }
        }
        return paths;
        
    }
    string T_DFS(int root,vector<vector<bool>> &tomadas){
        if(root == ogAdy.size()-1) return to_string(root+1);
        for(int u : ogAdy[root]){
            if(rRes[u][root] == 1 && !tomadas[root][u]){
                //Los caminos se indexan desde uno
                return to_string(root+ 1) + T_DFS(u,tomadas);

            }
        }
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
   
   
    cin >> N >> M   ;

    int tamañoGrafo = N;

    flow_digraph G(tamañoGrafo);
        
    fore(i,0,M){
        int a,b;
        cin >> a >> b;
        G.addPair(a-1,b-1);
            
    }
    int cant = G.maxFlow();
    
    vector<string> res =G.D_paths(cant);
    cout << cant << "\n";
    if(cant != 0){
    for(auto p : res){
        cout << p.size() << "\n";
        for(char x:p){
            
            cout << x << " ";
        }
        cout << "\n";
    }
    }   

}


