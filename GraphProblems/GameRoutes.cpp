#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = a; i >= (int)b;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
 
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5+1;
const int INDEF = -1;
vector<ll> memo(MAXN,INDEF);
 
struct digraph{
    vector<vector<int>> ady;
    digraph(int V){ady.resize(V);}
 
    void addEdge(int v,int w){
        ady[v].push_back(w);
    }
};
 
 
ll solve(int curr, digraph &G){
    if(memo[curr] != INDEF) return memo[curr];
    ll res = 0;
    for(int u : G.ady[curr]){
        res = (res + solve(u,G)) % MOD;
    }
    return memo[curr] = res;
}
 
 
 
 
int main(){
    FAST_IO
    int n,m;
    cin >> n >> m;
    int a ,b; digraph G(n);
    fore(i,0,m){
        cin >> a >> b; 
        G.addEdge(a-1,b-1);
    }
    //Caso base
    memo[n-1] = 1;
   
    cout << solve(0,G);
    
    
 
}
 