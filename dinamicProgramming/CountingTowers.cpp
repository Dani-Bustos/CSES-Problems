#include<bits/stdc++.h>
typedef long long ll;
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const ll MOD = 1e9 + 7;
const ll INF =  1e18;
const ll INDEF = -1; const ll MINF = -1e18;
const ll MAXN = 1e6+1;
vector<vector<ll>> memo(1e6+2,vector<ll>(2,INDEF));



ll fastexp(ll base, ll exp){
    if(exp == 0) return 1;
    if(exp == 1) return base;
    ll p = fastexp(base,exp/2);
    if(exp % 2 == 0) return p*p;
    else return p*p*base;
}


int main(){
    FAST_IO
    int t;
    cin >> t;
    int medio = 1;
    int sinMedio=0;
    
      
    fore(j,0,2) (j == medio) ? memo[0][j] = 1 : memo[0][j] = 1;

        
    //Dp bottom up, hay siempre dos opciones o estamos en un estado con una raya en el medio:" | " o sin " "
    //haciendo algunos dibujos, es facil ver a que estados es valido transicionar. Luego la dp se sigue de eso
    
    fore(lvl,1,MAXN){
        fore(p,0,2){
            if(p ==medio) memo[lvl][p] = (  memo[lvl-1][sinMedio] % MOD + 4*memo[lvl-1][medio] % MOD) % MOD;
            if(p ==sinMedio) memo[lvl][p] = (2*memo[lvl-1][sinMedio] % MOD + memo[lvl-1][medio] %  MOD) % MOD;
        }
    }  

    while(t--){
        int n; cin >> n;
         
        cout << (memo[n-1][sinMedio] + memo[n-1][medio]) % MOD << "\n";
    }
   
    
    

}


