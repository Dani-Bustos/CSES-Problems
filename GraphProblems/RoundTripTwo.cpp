#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a ; i < (int)b; i++) 
using namespace std;

int n ,m;
const int PAR = 2;
const int IMPAR = 1;
const int INDEF = -1;
int start = INDEF; int finish = INDEF;
struct digraph{
    vector<vector<int>> ady;
    vector<int> vis;
    vector<int> p;
    
    digraph(int V){
        ady.resize(V);
        p.resize(V);
        vis.resize(V,0);
    }

    void addEdge(int v, int w){
        ady[v].push_back(w);
    }

    void DFS(int u){
        vis[u] = 1;   
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
    
    

};
 
 
int main(){
    
    cin >> n >> m;
    
    digraph G(n);
    int a ,b;
    fore(i,0,m){
        cin >> a >> b;
        G.addEdge(a-1,b-1);
    }
 
    for(int i = 0; i < n && start == INDEF; i++){
        if(G.vis[i] == 0) G.DFS(i);
    }
    
    if(start == INDEF) cout << "IMPOSSIBLE";
    else{
        vector<int> res = G.buildCycle();
        cout << res.size() << "\n";
        for(int v : res){
            cout << v +1<< " ";
        }
    }
 
}