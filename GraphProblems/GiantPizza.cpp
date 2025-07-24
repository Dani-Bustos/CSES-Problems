#include<bits/stdc++.h>

#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fore(i,a,b) for(int i = a; i < (int)b;i++)
#define LOG2(x) 31  - __builtin_clz(x)
using namespace std;
int n,m;
typedef long long ll;
using digraph = vector<vector<int>>;
digraph G; digraph Grev;

vector<int> component;



void DFS(digraph &G,int root, int mark , vector<int> &postOrder){
    if(component[root] >=0) return;
    component[root] = mark;
    for(int w : G[root]) DFS(G,w,mark,postOrder);
    postOrder.push_back(root);
}
vector<int> SCC_IN(digraph &G,const vector<int> &order){
    vector<int> DFS_ORDER;
    component.assign(2*m,-1);
    for(auto v = order.rbegin();v != order.rend();v++) DFS(G,*v,*v,DFS_ORDER);
    return DFS_ORDER;
}

vector<int> SCC(){
    vector<int> order(2*m);
    iota(order.begin(),order.end(),0);
    SCC_IN(Grev,SCC_IN(G,order));
    return component;
}


inline int neg(int x){
    if(x >= m) return x-m;
    else return x+m;
}

int main(){
    FAST_IO
    cin >> n >> m;
    G.clear(); G.resize(2*m);
    Grev.clear(); Grev.resize(2*m);
    
    fore(i,0,n){
        int a,b;
        char s_a,s_b;
        cin >> s_a  >> a >> s_b >> b;

        a--;b--;
        a = s_a == '+' ? a : neg(a);
        b = s_b == '+' ? b : neg(b);
        G[neg(a)].push_back(b); Grev[b].push_back(neg(a));
        G[neg(b)].push_back(a); Grev[a].push_back(neg(b));
    } 
    SCC();
    bool possible = true;
    fore(i,0,m){
        if(component[i] == component[neg(i)]) possible = false,i = m+1;
    }
    if(not possible) cout << "IMPOSSIBLE";
    else{
        fore(i,0,m){
            char assigment = component[i] > component[neg(i)] ? '+' : '-';
            cout << assigment << " ";
        }
        
    }
}