#include<bits/stdc++.h>
typedef long long ll;
#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;
const ll INDEF = -1; const ll MINF = -1e17; const ll INF = 1e17;

struct edge{
    int vertex;
    ll cost;
    edge(){}
    edge(int v=-1,ll c =-1){
        vertex= v;
        cost =c;
    }
};

struct w_digraph{
    vector<vector<edge>> adyacencias;
    vector<pair<int,edge>> E;
    //Lo usamos para la dfs sobre el traspuesto
    vector<list<int>> adyacenciasIn;
    w_digraph(int cantVertices){
        adyacencias.resize(cantVertices);
        adyacenciasIn.resize(cantVertices);
    }

    void addEdge(int v,int w,ll weight){
        adyacencias[v].push_back(edge(w,weight));
        adyacenciasIn[w].push_back(v);
        E.push_back({v,edge(w,weight)});
        
    }
    
    pair<ll,bool> Bellman_Ford(int source){
        vector<ll> d(adyacencias.size(),INF);
        d[source] = 0;
        bool change = false;
        fore(i,0,adyacencias.size()-1){
            for(pair<int,edge> e : E){
                int v = e.first;
                int u = e.second.vertex; ll weight =e.second.cost;
                if(d[u]> d[v] + weight){
                d[u] = d[v] + weight; change = true;
                }
            }
            if(!change) i = adyacencias.size() + 1; 
            change = false;
            
        }
        vector<bool> marked(adyacencias.size(),false);
        //Buscamos ciclo negativo
        bool ciclo = false;
        for(pair<int,edge> e : E){
                int v = e.first;
                int u = e.second.vertex; int weight =e.second.cost;
                if(d[u]> d[v] + weight){
                    marked[u] = true;
                    d[u] = d[v] + weight;
                    ciclo =true;
                }
        }
        //Si hay un camino desde la raiz hasta algun elemento en un ciclo, y de ese elemento del ciclo al final, entonces podemos tener un score arbitrariamente alto
        if(ciclo){
            vector<bool> T = BFS_Transpuesto(adyacencias.size()-1);
            vector<bool> S = BFS(0);
            fore(i,0,T.size()){
                if(T[i] && S[i] && marked[i]) return {-1,false};
            }
        }
        
        pair<ll,bool> res = {d[adyacencias.size()-1],true};
        return res;  
    }  

    vector<bool> BFS_Transpuesto(int root){
        //Nos dice si hay camino de todos hacia la raiz
        vector<bool> d(adyacencias.size(),false);
        d[root] = true;
        queue<int> q;
        q.push(root);
        
        while(!q.empty()){
            int v = q.front(); q.pop();
            
           
            for(int e : adyacenciasIn[v]){
              
                if(!d[e]) q.push(e) ,d[e] = true;
            }
        }
        return d;
    }
    vector<bool> BFS(int root){
       //Nos dice si hay camino de la raiz hacia todos
        vector<bool> d(adyacencias.size(),false);
        d[root] = true;
        queue<int> q;
        q.push(root);
       
        while(!q.empty()){
            int v = q.front(); q.pop();
            
           
            for(edge vw : adyacencias[v]){
               int w = vw.vertex;
                if(!d[w]) q.push(w) ,d[w] = true;
            }
        }
        return d;
    }

    
    
};






int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    w_digraph G(n);
    fore(i,0,m){
        int a,b,x;
        cin >> a >> b >> x;
        G.addEdge(a-1,b-1,-x);

    }
    pair<ll,bool> res = G.Bellman_Ford(0);
    if(!res.second) cout << -1;
    else cout << (-1)*res.first;
}





