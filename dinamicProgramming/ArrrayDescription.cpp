#include<bits/stdc++.h>
typedef long long ll;
#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;

const ll MOD = 1e9 + 7;

const ll INDEF = -1; const int MINF = -1e9;
int n,m; //m:= upper bound para valores en el array
vector<int> arreglo(1e5+2);
vector<int> XPosition;
vector<ll> memo(1e5 + 2,INDEF);

int validSolution(){
    fore(i,0,n-1){
        if(abs(arreglo[i] - arreglo[i+1]) >1){
            return 0;
        }
    }
    return 1;
}
ll solve(int i){
    
    
    if(i == XPosition.size()-1){
        return validSolution();
    }
    //else if(memo[i] != INDEF) return memo[i];
    else{
       ll res = 0;
        
       
        fore(j,1,m+1){
            arreglo[XPosition[i]] = j;
            res = (res + solve(i+1)) % MOD;
        
        }
        
       // memo[i] = res;
        return res;
    }
    //return memo[XPosition[i]];
   


}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> n >> m;
    fore(i,0,n){
        cin >> arreglo[i];
        if(arreglo[i] == 0) XPosition.push_back(i);
    }
    
    //Posicion de llegada
    XPosition.push_back(n);
    if(XPosition.size() == 1) cout << 0;

    else{  
        ll res = 0;
        res = solve(0);
        cout << res;
    }
}


