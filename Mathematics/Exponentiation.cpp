#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = b; i >=a;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define LOG2(x) 31  - __builtin_clz(x)
const double PI = 3.141592653589793238462643;
typedef long long ll;

using namespace std;

const int MAXN = 1001;
const int INDEF = -1;
const ll INF = 1e18;

const ll MOD = 1e9 + 7;
int n;
ll fstExp(ll a,ll b){
    if(b == 0) return 1;
    if(b == 1) return a;
    ll half = fstExp(a,b/2);
    if(b % 2 == 0) return (half*half) % MOD;
    else return (((half*half) % MOD)*a) % MOD;
}


int main(){
    FAST_IO
    
   cin >> n;
   while(n--){
    ll a,b;
    cin >> a >> b;
    cout << fstExp(a,b) << "\n";
   }
   

}   

