
#include <bits/stdc++.h>

using namespace std;

#define fore(i,a,b) for(int i=a; i<b; i++)
typedef long long  ll;

    
int main(){
 int n;
 cin >> n;
 for( long long k= 1; k < n+1; k++){
  long long res = (k*k*(k*k - 1) / 2 ) /*Numero combinatorio*/ - ( (long long) pow((k-4),2)*4 + (k-4)*4*3 +(k-4)*2*4 + 24);
  cout << res << endl;  
 }

} 
   
    
   
   
   

 
 