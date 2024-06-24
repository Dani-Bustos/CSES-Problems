#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;


const int MAXN = 2*1e6;
int a[MAXN];

bool solve(int n,ll target,int k){
    ll sumaAct = 0;
    ll divs = 0;

    fore(i,0,n){
        if(a[i] > target){
            return false;
        }else if(a[i] + sumaAct > target){
            divs++;
            sumaAct = 0;
            i--;
        }else{
            sumaAct += a[i];
        }    
        if(i == n - 1){
            divs++;
        }
    }
    
    
    if (divs <= k){
        return true;
    }else{
        return false;
    }
}
int main(){
 FIN
 ll n;ll k;
 ll INF = 2e5*1e9 ;
 cin >> n >> k;
 ll total = 0;

 fore(i,0,n){
     cin >> a[i];
     total +=a[i];
 }
 ll res=  INF;
 ll l = 1; ll r = INF; ll act; 
 while(l < r){
     act =  (l + r) /2; 
     
    // cout << "act " << act << " ";
     bool state = solve(n,act,k);
     if(state == true){
         r = act;
     }else{
         l = act + 1;
     }
  
 }


   cout << l;
}
