#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = a; i >= (int)b;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXNUM = 1e5+1;
/*
solve(int i , ll sum){
    if(sum == 0) return 1
    if(sum < 0 )return 0;
    if(i == 0 && sum > 0) return 0;
    return solve(i-1,sum - i) + solve(i-1,sum) 
}
*/


ll target;

int main(){
    FAST_IO
    int n; cin >> n;
    //Idea: Sabemos que la solucion existe si solo si , la suma de gauss es divisible por dos
    //Esto solo ocurre si n % 4 == 3 || == 0. 
    //Entonces tan solo necesitamos elegir la mitad de la suma de gauss, ya que eso nos define una forma
    // de formarnos conjuntos distintos iguales.
    //la dp entonces tiene complejidad O(n*Gauss/2)= O(n*(n*(n+1)/4)) <= O(n³)
    if(n % 4 == 1 || n %  4 == 2) cout << 0;
    else{
        target = n*(n+1)/4;
        vector<vector<ll>> dp(n+2,vector<ll>(target + 1));
        fore(i,1,n+2) dp[i][0] = 1;

        fore(i,1,n+1){
            fore(j,1,target+1){
                if(j - i >= 0) dp[i][j] = (dp[i-1][j-i] + dp[i-1][j]) % MOD;
                else dp[i][j] = dp[i-1][j] % MOD;
        }
        }
        cout << dp[n][target];
    }

}



