#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 

 
 
int main(){
    FIN
    int n;
    cin >> n;
    long long a[n];
    fore(i,0,n){
      cin >> a[i];
    
    }
    long long res = (long long)pow(-10,9);long long suma =(long long) pow(-10,9) ;
    fore(i,0,n){
         suma = max(a[i],suma +a[i]);
         res = max(suma,res);
    }
    
    cout << res;
}
