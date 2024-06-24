#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;


ll gauss(ll a){
    return (a*(a+1)) / 2;
}

int main(){
 FIN
 int n;int k;
 
 cin >> n >> k;
 ll a[n];
 fore(i,0,n){
     cin >> a[i];
 }
 ll res = 0;
 fore(i,0,n){
    set<int> s;    
     fore(j,i,n){
         s.insert(a[j]);
         if(s.size() <= k){
             res++;
         }
     }
 }
cout << res;
}

