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
    component.assign(n,-1);
    for(auto v = order.rbegin();v != order.rend();v++) DFS(G,*v,*v,DFS_ORDER);
    return DFS_ORDER;
}

vector<int> SCC(){
    vector<int> order(n);
    iota(order.begin(),order.end(),0);
    SCC_IN(Grev,SCC_IN(G,order));
    return component;
}
void DFS(int root,vector<bool> &visited){
    if(visited[root]) return;
    visited[root] = true;
    for(int w : G[root]){
        DFS(w,visited);
    }
}

int main(){
    FAST_IO
    cin >> n >> m;
    G.clear(); G.resize(n);
    Grev.clear(); Grev.resize(n);
    component.resize(n); 
    fore(i,0,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        
        G[a].push_back(b); Grev[b].push_back(a);
    } 
    vector<int> components = SCC();
    if(count(component.begin(),component.end(),component[0]) == component.size()) cout << "YES";
    else{
        cout << "NO" << "\n";
        int destiny;
        int og = 0;
        //necesariamente alguno debe no estar en la Comp conexa del 0
        fore(i,1,n){
            if(component[i] != component[og]) destiny = i,i = n+1;
        }
        //Hay que averiguar desde que lado no es alcanzable
        vector<bool> visited(n,false);
        DFS(0,visited);
        if(visited[destiny]) swap(og,destiny);
        cout << og +1 << " " << destiny + 1;
    }

}