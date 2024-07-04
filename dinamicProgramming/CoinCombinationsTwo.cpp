#include<bits/stdc++.h>
typedef  long long ll;
#define fore(i,a,b) for(int i = a; i<b;i++)

using namespace std;

const long long INDEF = -1;

vector<long long> MEMO;
const int MOD = 1e9 + 7;

int n, x; //n:= cantidad de monedas, x:= suma deseada
vector<int> coins;
long long solve(){
    MEMO[0] = 1;
    //Dp bottom up con optimizacion de memoria
    fore(i,0,n){
        fore(j,0,x + 1){
            if(j - coins[i] >= 0 ){
                MEMO[j] =  (MEMO[j] + MEMO[j - coins[i]]) % MOD;
            }
        }
    }
    return MEMO[x];
}
int main(){
   
    cin >> n >> x;
    MEMO.resize(x+1);
    coins.resize(n);
    fore(i,0,n){
        cin >> coins[i];
    }
    cout << solve();

    
}
