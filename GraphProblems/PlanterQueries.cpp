#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i = a; i < (int)b; i++)
#define dfore(i,a,b) for(int i = a; i >= (int)b; i--)
#define FAST_IO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define LOG2(x) 32  - __builtin_clz(x)-1

const int MAXN = 2*1e5 + 1;
const int MAXPOW = 30;
struct digraph{
    vector<vector<int>> ady;
    //Este problema NO ENTRA si usamos un vector
    int mat[200001][30];
    digraph(int V) {ady.resize(V);}
    void addEdge(int v,int w){
        ady[v].push_back(w);
        
    }

    int toPower(int i){return LOG2(i) ;};
    
    void preCompute(const int maxK){
        
        
        
        for(int i = 0; i <= LOG2(maxK);i++){
            fore(v,0,ady.size()){
                if(i == 0) mat[v][i] = ady[v][0]; 
                else{ 
                    mat[v][i] = mat[mat[v][i-1]][i-1];
                }
        }
        
        }
    
    }
    vector<int> powersOfTwo(const int num){
        vector<int> powers;
        int i = 1;
        while(i <= num){
            if (i & num) powers.push_back(i);
            i = i << 1;
        }
        return powers;
    }
    int computeQuery(const int x, const int k){
        
        int fst = x;
        
        int i = 1;
        while(i <= k){
            if (i & k) fst = mat[fst][toPower(i)];
            i = i << 1;
        }
        return fst;
    }

};

int n,q;
int main(){
    FAST_IO
    cin >> n >> q;
    digraph G(n);
    fore(i,0,n){
        int temp;
        cin >> temp;
        G.addEdge(i,temp-1);
    }
    int MAXK = 1e9 + 1;
    G.preCompute(MAXK);
    fore(test,0,q){
        int x,k;
    
        cin >> x >> k;
        x--;
        cout << G.computeQuery(x,k) + 1 << "\n";
        
    }   

}