#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll; 
using namespace std;


 
 
int main(){
    int n;
    cin >> n;
    pair<long long,int> numeros[n];
    
    fore(i,0,n){
        cin >> numeros[i].first;
        numeros[i].second = i;
    }
    sort(numeros,numeros + n);  

    int rondas = 1;
    fore(i,1,n){
        if(numeros[i-1].second > numeros[i].second){
         rondas = rondas + 1;   
        }
    }
    cout << rondas;

}