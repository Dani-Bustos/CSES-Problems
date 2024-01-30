#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
int main(){
    FIN
    int n;
    cin >> n;
    pair<int,int> a[n*2];
    fore(i,0,2*n){
        int llegada,salida = 0;
        cin >> llegada >> salida;
        a[i].first = llegada;
        a[i].second = 1;
        i++;
        a[i].first = salida;
        a[i].second = -1;
        
    }
    sort(a,a+n*2);
    int maxim = 0;
    int actual = 0;
    int i = 0;
    while(i < 2*n){
        int momento = a[i].first;
        while(momento == a[i].first){
            actual += a[i].second;
            i++;
        }
        maxim = max(actual,maxim);
    }
    cout << maxim;
    
    

}
