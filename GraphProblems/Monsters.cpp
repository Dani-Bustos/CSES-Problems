#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)
typedef long long ll ;
const ll INF = 1e15;

struct ComparePairs {
    bool operator()(const pair<ll, int>& p1, const pair<ll, int>& p2) {
        // Compare first elements; if equal, compare second elements
        return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);
    }
};


struct edge{
    int vertex;
    ll cost;
    edge(int v=-1,ll c =-1){
        vertex= v;
        cost =c;
    }
};

struct digraph{
    vector<list<edge>> adyacencias;

    digraph(int cantVertices){
        adyacencias.resize(cantVertices);
    }

    void addEdge(int v,int w,ll weight){
        adyacencias[v].push_back(edge(w,weight));
    }
    
    vector<ll> Djikstra(int root){
        vector<bool> visitado(adyacencias.size(),false);
        vector<ll> d(adyacencias.size(),INF);
        d[root] = 0;
        
        priority_queue<pair<ll,int>,vector<pair<ll,int>> ,ComparePairs> q;
        q.push({0,root});
        while(!q.empty()){
            int v;ll act; tie(act,v) = q.top(); q.pop();
            
            if(visitado[v]) continue;
            visitado[v] = true;
            
            for(edge w: adyacencias[v]){
                if(not visitado[w.vertex] && d[w.vertex] > w.cost + act){ 
                    d[w.vertex] = w.cost + act;
                    //El heap default es max
                    if(not visitado[w.vertex]) q.push({d[w.vertex],w.vertex});   
                }
            }
        }
        return d;
    }

};





int main(){
    int n, m;
    cin >> n >> m;
    digraph G(n);
    fore(i,0,m){
        int a,b; ll c;
        cin >> a >> b >> c;
        G.addEdge(a-1,b-1,c);
    }
    vector<ll> res = G.Djikstra(0);
    for(ll num : res){
        cout << num << " ";
    }
}