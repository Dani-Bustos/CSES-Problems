#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
typedef long long ll;
 
void solve(int discos , int actual , int voy){
    if(discos == 1){
      cout << actual << " " << voy << "\n"; 
    }else{
    if(actual != 1 && voy != 1){
     solve(discos -1,actual,1);
    cout << actual << " " << voy<< "\n";
     solve(discos-1,1,voy);
      }else if(actual != 2 && voy != 2){
         solve(discos-1,actual,2);
         cout << actual << " " << voy << "\n";
         solve(discos-1,2,voy);
      }else if(actual != 3 && voy != 3){
         solve(discos-1,actual,3);
         cout << actual << " " << voy << "\n";
         solve(discos-1,3,voy);
      }
    }
}
 
 
 
int main(){
 FIN
 int n; cin >> n;
 cout << pow(2,n) -1  << endl;
 solve(n,1,3);
}