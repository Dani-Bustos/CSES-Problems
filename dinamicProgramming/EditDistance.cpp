#include<bits/stdc++.h>
typedef long long ll;
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const ll MOD = 1e9 + 7;
const ll INF =  1e18;
const ll INDEF = -1; const ll MINF = -1e18;
int n;




int main(){
    FAST_IO
    string n,m;
    cin >> n >> m;
    int lm = m.size()+1;
    int ln = n.size()+1;
    vector<vector<ll>> memo(ln,vector<ll>(lm,INF));
    //Caso base
 
    fore(i,0,n.size()+1) memo[i][0] = i;
    fore(j,0,m.size()+1) memo[0][j] = j;
    //Dp Bottom up, son todas las maneras de  cortar a cada paso
    fore(i,1,n.size()+1) {
        fore(j,1,m.size()+1){
            int cost = n[i-1] == m[j-1]? 0 : 1;
            memo[i][j] = min(1 + memo[i][j-1],min(1 + memo[i-1][j], cost + memo[i-1][j-1]));
                        //   le agrego uno a n,   le saco uno a n, transformo uno en el otro si hiciese falta
        }
    }
   cout << memo[n.size()][m.size()];   
    
    

}


