#include<bits/stdc++.h>

#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;

typedef long long ll;
ll MOD = 1e9 + 7;
const ll INDEF = -1; const int MINF = -1e9;
int n;


vector<int> precios(1002);
vector<int> paginas(1002);


    

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int X;
    cin >> n >> X;
    fore(i,0,n){
       cin >> precios[i];
    }
    fore(i,0,n){
        cin >> paginas[i];
    }
    
   
    vector<int> memo(X+1,0);
    //Dp Bottom up f(libroActual,plataActual)
    vector<int> memoAct(X+1,0);
    fore(t,0,n){
        fore(i,0,X+1){
            if (i - precios[t] >= 0) memoAct[i] = max(memo[i-precios[t]] + paginas[t],memo[i]);
            
        }
        memo = memoAct;
    }
    cout << memo[X];
}


