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
    int numComponents;
    int maximumSize;
    vector<int> parent;
    
    DSU(int num){
        size.clear(); size.resize(num,1);
        parent.clear(); parent.resize(num);
        fore(i,0,num) parent[i] = i;
        numComponents = num;
        maximumSize = 1;
    }

    void join(int x,int y){
        int repX = find(x); int repY = find(y);
        if(repX == repY) return;
        else {
            if(size[repY] > size[repX])   swap(repY,repX);    
            parent[repY] = repX;
            size[repX] += size[repY];  
            maximumSize = max(maximumSize,size[repX]);
            numComponents--;
        }
    }
    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
};




int main(){
    FAST_IO
    cin >> n >> m;
    G.clear(); G.resize(n);
    DSU CC(n);
    fore(i,0,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        CC.join(a,b);
        cout << CC.numComponents << " " << CC.maximumSize << "\n";

    } 
    

}