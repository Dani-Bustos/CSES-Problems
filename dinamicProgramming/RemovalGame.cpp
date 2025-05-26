#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = a; i >= (int)b;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define mp make_pair
using namespace std;

typedef long long ll;






int main(){
    FAST_IO
    int n; cin >> n;
    vector<ll> nums(n);
    fore(i,0,n) cin >> nums[i];
    //dp : R² -> R²
    //dp(i,j) := mejores scores del 1er y 2do jugador usando numeros del rango [i,j] 
    
    vector<vector<pair<ll,ll>>> dp(n,vector<pair<ll,ll>>(n));
    //casos base, el rango  [i,i] es usar la moneda que esta ahi, el 2do no se lleva nada
    fore(i,0,n) dp[i][i] = {nums[i],0};
    //dp bottom up, las transiciones son siempre elegir entre la primera o la ultima, y el mejor score del "segundo" jugador en el nuevo rango, ya que ahora elige el oponente
    fore(delta,1,n){
        int i = 0;
        int j = i + delta;
        while(j < n){
            dp[i][j] = max(
                make_pair(dp[i+1][j].second + nums[i],dp[i+1][j].first),
                make_pair(dp[i][j-1].second + nums[j],dp[i][j-1].first));
            
            i++; j++;
        }
    }
    cout << dp[0][n-1].first;

    

}



