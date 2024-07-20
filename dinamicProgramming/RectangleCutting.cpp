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
    int a,b;
    cin >> a >> b;
    vector<vector<ll>> memo(a+1,vector<ll>(b+1,INF));
     
    fore(i,0,min(a,b)+1)memo[i][i] = 0;
    //O(n³) 
    fore(i,1,a+1){
        fore(j,1,b+1){
            //corto todas las cosas x
            if(i == j) continue;
            fore(I,1,i) memo[i][j] = min(memo[i][j], 1 + memo[I][j] + memo[i -I][j]);
            fore(J,1,j) memo[i][j] = min(memo[i][j], 1 + memo[i][J] + memo[i][j - J]);
        }
    }
    cout << memo[a][b];

}


