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
  
    w_digraph(int cantVertices){
        adyacencias.resize(cantVertices);
        
    }

    void addEdge(int v,int w,ll weight){
        adyacencias[v].push_back(edge(w,weight));
       
        E.push_back({v,edge(w,weight)});
        
    }
   
    pair<bool,vector<int>> Bellman_Ford(int source){
        
        vector<ll> d(adyacencias.size(),INF);
        vector<int> p(adyacencias.size(),-1);
        d[source] = 0;
        
        bool change = false;
        fore(i,0,adyacencias.size()-1){
            for(pair<int,edge> e : E){
                int v = e.first;
                int w = e.second.vertex; ll weight =e.second.cost;
                
                if( d[v] + weight < d[w]){
                    d[w] = d[v] + weight; change = true;
                    p[w] = v;
                }
            }
            if(!change) break;
            change = false;
            
        }
        
        //Buscamos ciclo negativo
    
        for(pair<int,edge> e : E){
                int u = e.first;
                int v = e.second.vertex; ll weight =e.second.cost;
                if( d[u] + weight <d[v]){
                    p[v] = u;
                    //Construyo ciclo 
                    vector<bool> visited(adyacencias.size(),false);
                    visited[v] = true;
                    while(not visited[u]){
                        visited[u] = true;
                        u = p[u];
                    }
                    vector<int> ciclo; ciclo.push_back(u);
                    v = p[u];
                    while( v != u){
                       
                        ciclo.push_back(v);
                        v = p[v];
                    }
                    ciclo.push_back(u);
                    reverse(ciclo.begin(),ciclo.end());
                    return {true,ciclo};
                    
                }
        }
        
        
        return {false,{}};
    }  

   
    
    

    
    
};






int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    w_digraph G(n+1);
    //Como no sabemos si el grafo es conexo, conectamos un vertice fantasma con 0 a toods
    fore(i,1,n+1){
        G.addEdge(0,i,(ll) 0);
    }
    
    fore(i,0,m){
        int a,b; ll x;
        cin >> a >> b >> x;
        if( a == b && x < 0){ cout << "YES" << "\n" << a << " " << b; return 0;}
        G.addEdge(a,b,x);

    }
    pair<bool,vector<int>> res = G.Bellman_Ford(0);
    if(!res.first) cout << "NO";
    else {
        cout << "YES" << "\n"; 
        fore(i,0,res.second.size()){
        cout << res.second[i] << " ";
        }
    }
}





