#include<bits/stdc++.h>
typedef long long ll;
#define fore(i,a,b) for(int i = a; i< b;i++)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const ll MOD = 1e9 + 7;

const ll INDEF = -1; const int MINF = -1e9;
int n,m; //m:= upper bound para valores en el array
vector<int> arreglo(1e5+2);
vector<vector<ll>> memo(1e5 + 2,vector<ll>(104,INDEF));



//Si estoy en la posicion i-esima y quiero poner el numero m, cuantas maneras hay


//Forma recursiva , da TLE pero la dejo por propositos didacticos
/*
ll solve(int i,int num){
    if(num <= 0 || num > m) return 0;
    else if(i == 0 && (arreglo[i] == num || arreglo[i] == 0)) return 1;
    else if(arreglo[i] == 0 || arreglo[i] == num) memo[i][num] = solve(i-1,num)% MOD + solve(i-1,num + 1) % MOD + solve(i-1,num-1) % MOD;
    else if(arreglo[i] != num) return 0;
    else if(memo[i][num] != INDEF) return memo[i][num];
    
  
    return memo[i][num];
}
*/

int main(){
    FAST_IO
    cin >> n >> m;
    fore(i,0,n){
        cin >> arreglo[i];
        
    }
    
    
    ll res =0;
    //fore(i,1,m+1){
    //    res = (res + solve(n-1,i )) % MOD ;
   // }
    //cout << res;

    fore(num,1,m+1) memo[0][num] = (arreglo[0] == num || arreglo[0] == 0);
    fore(i,1,n){
        fore(num,1,m+1){
            if(arreglo[i] == 0 || arreglo[i] == num) {
                memo[i][num] = memo[i-1][num]% MOD +( num + 1 <= m ? memo[i-1][num + 1]:0) % MOD +(num - 1 > 0?  memo[i-1][num-1] : 0) % MOD;
            }else if(arreglo[i] != num) memo[i][num] = 0;
        }
    }
    fore(num,1,m+1) res = (res + memo[n-1][num]) % MOD;
    cout << res;
}


