#include<bits/stdc++.h>

#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;

const ll MOD = 1e9 + 7;
typedef long long ll;
ll MOD = 1e9 + 7;
const ll INDEF = -1; const int MINF = -1e9;
int n,m; //m:= upper bound para valores en el array
vector<int> arreglo(102);
vector<int> XPosition;
vector<vector<ll>> memo(103,vector<ll>(1002,INDEF));
vector<ll> res;

vector<bool> h;
ll solve(int i ,int num){
    if(i == n){ res.push_back(num); return num;}
    if(memo[i][num] != INDEF) return memo[i][num];
    else{
        ll res = 0; 
        solve(num - arreglo[i],i+1);
        solve(num,i+1);
    }
    


}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> n;
    ll tot = 0;
    fore(i,0,n){
        cin >> arreglo[i];
        tot += arreglo[i];
        
    }
    
   
        ll res = 0;
        res = solve(0,tot);
        cout << res;
    
}


