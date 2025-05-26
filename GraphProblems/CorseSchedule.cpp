#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a ; i < (int)b; i++) 
using namespace std;

int n ,m;

const int INDEF = -1;
int start = INDEF; int finish = INDEF;

vector<int> Order;
struct digraph{
    vector<vector<int>> ady;
    vector<vector<int>> adyIN;
    vector<int> vis;
    vector<int> p;
    
    
    digraph(int V){
        ady.resize(V);
        adyIN.resize(V);
        p.resize(V);
        vis.resize(V,0);
    }

    void addEdge(int v, int w){
        ady[v].push_back(w);
        adyIN[w].push_back(v);
    }
    /*
    void DFS(int u){
        vis[u] = 1;   
        Order.push_back(u);
        PROCCESSED++;
        for(int v : ady[u]){
            if(!vis[v]){
                p[v] = u;
                DFS(v);
                if(start != INDEF) return;
            }else if(vis[v] == 1){
                finish = u;
                start = v;
                return;
            }
        }
        vis[u] = 2;
    }
    
    vector<int> buildCycle(){
        vector<int> res;
        res.push_back(start);
        for(int u = finish; u != start; u = p[u]){
            res.push_back(u);
        }
        res.push_back(start);
        reverse(res.begin(),res.end());
        return res;
    }
    */
    

};
 
 
int main(){
    
    cin >> n >> m;
    
    digraph G(n);
    int a ,b;
    vector<int> req(n);
    fore(i,0,m){
        cin >> a >> b;
        G.addEdge(a-1,b-1);
        req[b-1]++;
    }
    stack<int> disp;
    fore(i,0,n) if(G.adyIN[i].size() == 0)disp.push(i);
    
    int PROCESSED = 0;
    while(!disp.empty()){
        int v = disp.top(); disp.pop();
        Order.push_back(v);
        PROCESSED++;
        for(int w : G.ady[v]){
            req[w]--;
            if(req[w] == 0) disp.push(w);
        }
    }
    if(PROCESSED == n){
        for(int v : Order) cout << v + 1 << " ";
    }else cout << "IMPOSSIBLE";
}