#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 

 
 
int main(){
    FIN
    int n,a,b;
    cin >> n >> a >> b;
    long long arr[n];
    fore(i,0,n){
      cin >> a[i];
    
    }
    a
    long long res = -1e9;long long suma = -1e9 ;
    int len = 0;
    fore(i,0,a){
        suma = max(arr[i],suma + arr[i]);
        res = max(suma,res);
    }

    fore(i,0,n){
         suma = max(arr[i],suma +arr[i]);
         res = max(suma,res);
    }
    
    cout << res;
}
