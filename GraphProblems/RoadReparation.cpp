#include<bits/stdc++.h>

#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fore(i,a,b) for(int i = a; i < (int)b;i++)
#define LOG2(x) 31  - __builtin_clz(x)
using namespace std;
int n,m;
typedef long long ll;
using graph = vector<vector<pair<int,ll>>>;
graph G;

struct Edge{
    int v,w;
    ll weight;
    Edge(int a,int b,ll cost):v(a),w(b),weight(cost){}
    
    bool operator <(const Edge& snd) const{
        return weight < snd.weight;
    }
};
vector<Edge> listaAristas;
struct DSU{
    vector<int> size;
    
    vector<int> parent;
    
    DSU(int num){
        size.clear(); size.resize(num,1);
        parent.clear(); parent.resize(num);
        fore(i,0,num) parent[i] = i;
    }

    void join(int x,int y){
        int repX = find(x); int repY = find(y);
        if(repX == repY) return;
        else {
            if(size[repY] > size[repX])   swap(repY,repX);    
            parent[repY] = repX;
            size[repX] += size[repY];  
        }
    }
    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
};

ll Kruskall(){
    DSU CC(n);
    sort(listaAristas.begin(),listaAristas.end());
    
    ll total = 0;
    int aristasPuestas = 0;
    fore(i,0,listaAristas.size()){
        int repV = CC.find(listaAristas[i].v);
        int repW = CC.find(listaAristas[i].w);
        if(repV != repW){
            total += listaAristas[i].weight;
            CC.join(repV,repW);
            aristasPuestas ++;
        }
    }
    if(aristasPuestas != n-1) return -1;
    else return total;
}

int main(){
    FAST_IO
    cin >> n >> m;
    G.clear(); G.resize(n);
    fore(i,0,m){
        int a,b; ll c;
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
        Edge e(a,b,c);
        listaAristas.push_back(e);

    } 
    ll ans = Kruskall();
    if(ans == -1) cout << "IMPOSSIBLE";
    else cout << ans;

}