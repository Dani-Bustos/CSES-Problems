#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;


int main(){
    FIN
    int n; 
    cin >> n;
    ll libros[n];
    fore(i,0,n){
        cin >> libros[i];
    }
    sort(libros,libros + n);
    ll suma = 0;
    ll best = 0;
    fore(i,0,n){
        if(libros[i] < suma){
            suma +=libros[i];
        }else{
            best = libros[i];
            suma += libros[i];
        }
    }
    ll res = 0;
    if(best*2 < suma){
        res = suma;
    }else{
        res = best*2;
    }
    cout << res;
}  