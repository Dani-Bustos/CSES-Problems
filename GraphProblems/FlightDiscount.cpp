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
    //Lo usamos para djikstra sobre el traspuesto
    vector<vector<edge>> adyacenciasIn;
    w_digraph(int cantVertices){
        adyacencias.resize(cantVertices);
        adyacenciasIn.resize(cantVertices);
    }

    void addEdge(int v,int w,ll weight){
        adyacencias[v].push_back(edge(w,weight));
        adyacenciasIn[w].push_back(edge(v,weight));
        
        
    }
    
    vector<ll> Djikstra(int root, bool transpose = false){
        vector<ll> d(adyacencias.size(),INF);
        //Recordar que pq es por default max-heap
        priority_queue<pair<ll,int>> q;
        q.push({0,root});
        d[root] = 0;
        while(!q.empty()){
            int v; ll dist; tie(dist,v) = q.top(); q.pop();
            //Como la pq es max heap, operamos con negativos
            dist  = dist*(-1);
            if(d[v] != dist) continue;
            
            if(!transpose){
                for( edge vw : adyacencias[v]){
                    ll c = vw.cost; int w = vw.vertex;
                    if(d[w] == INF || d[w] > dist + c){
                        d[w] = dist + c, q.push({-d[w],w});
                    }
                }
            }else{
                for( edge vw : adyacenciasIn[v]){
                    ll c = vw.cost; int w = vw.vertex;
                    if(d[w] == INF || d[w] > dist + c){
                        d[w] = dist + c, q.push({-d[w],w});
                    }
            }

            } 
        }
        return d;


    
    }
    
    
};






int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,edge>> E;
    w_digraph G(n);
    fore(i,0,m){
        int a,b; ll x;
        cin >> a >> b >> x;
        G.addEdge(a-1,b-1,x);
        E.push_back({a-1,edge(b-1,x)});

    }
    vector<ll> fromRootToAll = G.Djikstra(0,false);
    vector<ll> fromAllToEnd = G.Djikstra(n-1,true);

    ll res = fromRootToAll[n-1];
    for(pair<int,edge> e : E){
        int v = e.first; int w = e.second.vertex; ll c = e.second.cost;
        res = min(res,fromRootToAll[v] + c/2 +fromAllToEnd[w]);
    }
    cout << res;
}





