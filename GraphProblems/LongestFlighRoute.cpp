#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = a; i >= (int)b;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

const int INDEF = -1; const ll INF = 1e18; const int MINF = -1e9;
vector<ll> memo;



struct digraph{
    vector<vector<int>> ady;
    vector<vector<int>>inAdy;
    digraph(int V){ady.resize(V), inAdy.resize(V);}

    void addEdge(int v,int w){
        ady[v].push_back(w);
        inAdy[w].push_back(v);
    }

    
    
};



int maxFlights(int curr, digraph &G){
    if(memo[curr] != INDEF) return memo[curr];
    int res = MINF;
    for(int u: G.ady[curr]){
        res = max(res, 1 + maxFlights(u,G));
    }
    return memo[curr] = res;
}





int main(){
    FAST_IO
    int n,m;
    cin >> n >> m;
    int a ,b; digraph G(n);
    memo.resize(n,INDEF);
    fore(i,0,m){
        cin >> a >> b; 
        G.addEdge(a-1,b-1);
       
    }
    
    
    memo[n-1] = 1;
    ll maximo = maxFlights(0,G);
    if(maximo <= 0) cout << "IMPOSSIBLE";
    else{
    vector<int> res; res.push_back(0);
    int curr = 1;
    int i = 0;
    while(i!=n-1){
        int toGo;
        for(int v : G.ady[i]){
            if(memo[v] + curr  == maximo){
                curr++,res.push_back(v);
                toGo = v;
                break;
            }
        }
        i = toGo;
    }
    cout << maximo << "\n";
    for(int v : res){
        cout << v +1 << " ";
    }
    }
}



