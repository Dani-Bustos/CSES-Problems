#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll; 
using namespace std;



 
 
int main(){
    int n;
    cin >> n;
    long long monedas[n];
    ll total = 0;
    fore(i,0,n){
        cin >> monedas[i];
        total += monedas[i];
    }
    sort(monedas,monedas + n); //n*log(n)
    ll res = 0;
    if(monedas[0] > 1){
        res = 1;
    }else{
    
        ll suma = monedas[0];
    
        fore(i,1,n){
            if(monedas[i] > suma + 1){
                res = suma + 1;
                break;
            }else{
                suma += monedas[i];
            }


        }
    
        if(suma == total){
            res = suma + 1;
        
        }
    }
    cout << res;
}