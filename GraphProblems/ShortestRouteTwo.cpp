#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)
typedef long long ll ;
const ll INF = 1e15;
vector<vector<ll>> M;
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

struct graph{
    vector<vector<ll>> adyacencias;

    graph(int cantVertices){
        adyacencias.resize(cantVertices,vector<ll>(cantVertices,0));
    }

    void addEdge(int v,int w,ll weight){
        if(adyacencias[v][w] == 0 || weight <adyacencias[v][w] ){

        adyacencias[v][w]=weight;
        adyacencias[w][v] = weight;
        M[v][w] = weight;
        M[w][v] = weight;
        }
    }
    
    void Floyd_Warshall(){
                   
        fore(i,0,adyacencias.size()) fore(j,0,adyacencias.size()){ 
            if(adyacencias[i][j] !=0 && i!=j) M[i][j] = adyacencias[i][j];
            else if(i == j) M[i][i] = 0;
            else M[i][j] = INF;}
        
        fore(k,0,adyacencias.size()){
            fore(i,0,adyacencias.size()){
                fore(j,0,adyacencias.size()){ 
                    M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
                }
            }
        }

    }

    

};





int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m,q;
    cin >> n >> m >> q;
    M.resize(n,vector<ll>(n,0));
    graph G(n);
    fore(i,0,m){
        int a,b; ll c;
        cin >> a >> b >> c;
        G.addEdge(a-1,b-1,c);
    }
    G.Floyd_Warshall();

    fore(i,0,q){
        int a,b;
        cin >> a >> b;
        if(a!=b && M[a-1][b-1] == INF ) cout  << -1 << "\n";
        else cout << M[a-1][b-1] << "\n";

    }
}