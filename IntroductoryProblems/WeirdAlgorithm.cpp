
#include <bits/stdc++.h>

using namespace std;

#define fore(i,a,b) for(int i=a; i<b; i++)
typedef long long  ll;



int main(){
   long long n;
   cin >> n;
   while(n != 1){
      cout << n << " "; 
      
      if(n % 2 == 0){
         n = n/2;

      }else{
         n = n*3 + 1;
      }
   }
 
   cout << n;
 } 