#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std ;
typedef long long ll;
 
void solve(long long manzanas[],long long sumaTotal,vector<long long> &Todas,int actual,int n){
  if(actual == n){
    Todas.push_back(sumaTotal);
  }else{
    
    solve(manzanas,sumaTotal,Todas,actual +1,n);
    sumaTotal += manzanas[actual]; 
    solve(manzanas,sumaTotal,Todas,actual +1,n);
  }
 
}
int main(){
    int n; cin>>n;
    long long manzanas[n];
    ll sumaTotal=0;
    
    vector<long long> Todas;
    fore(i,0,n){
       
       cin >> manzanas[i]; 
       sumaTotal = sumaTotal + manzanas[i];
    }
    solve(manzanas,0,Todas,0,n);   
    ll res = sumaTotal;
    Todas.pop_back(); // porque el ultimo tiene todas y eso no es valido como opcion
    for(auto x : Todas){
              
       ll otro = sumaTotal - x;
       res = min(res,abs(otro-x)); 
    } 
    cout << res;
 
}