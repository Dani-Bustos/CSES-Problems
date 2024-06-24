#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;

bool ordenar(pair<int,int> a, pair<int,int> b){
    
        return a.second<b.second;
  
}


int main(){
    FIN
    int n;
    cin >> n;
    pair<int,int> a[n];
    fore(i,0,n){
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n,ordenar);
    int res = 0;
    int i = 0;
    int Ultinicio = a[i].second;
    i++;res++;
    while(i<n){
        
        if(a[i].first >= Ultinicio){
           res++;
           Ultinicio = a[i].second;
        }
       i++;
    }
    cout << res;

}
