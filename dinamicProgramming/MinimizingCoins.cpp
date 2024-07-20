#include<bits/stdc++.h>
typedef long long ll;
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const ll MOD = 1e9 + 7;
const ll INF =  1e18;
const ll INDEF = INF; const ll MINF = -1e18;
int n;




int main(){
    FAST_IO
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    
    fore(i,0,n) cin >> coins[i];
    vector<ll>memo(x+1,INDEF);
    memo[0] = 0;
    fore(curr,0,x+1) {
        fore(j,0,n){
            if (curr-coins[j]>=0){
                memo[curr] = min(memo[curr],memo[curr-coins[j]]+1);
            }
        }
    }

    if(memo[x]!= INDEF) cout << memo[x];
    else cout << -1;
   
    
    

}


