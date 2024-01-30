#include <bits/stdc++.h>
 
using namespace std;
 
#define fore(i,a,b) for(int i=a; i<b; i++)
typedef long long  ll;
 
 
 
int main(){
   long long n;
   cin >> n;
   long long modeador = (long long ) pow(10,9) + 7;
   long long res = 1;
   fore(i,0,n){
     res = res*2 % modeador;
   } 
   
   
   cout << res;
   
   
 
 
 } 