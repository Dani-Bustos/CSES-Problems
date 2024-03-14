#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;


ll gauss(ll a){
  // cout << "gauss(" << a << ")  ";
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
 ll i = 0;ll j = -1;
 ll res = 0; 
 map<ll,ll> contador;
 
 pair<ll,ll> last = {0,-1};
 while(i < n && j < n && last.second != n-1){
    j++;
    contador[a[j]]++;
    ll change = 0;
    if(contador.size() <= k){
       if(last.second >= i  ){
                ll temp;
                temp = j - i + 1;
               // cout << " res += gauss(" << temp <<")  - gauss("<< last.second - i + 1 << ") i: " << i << "j: " << j << " \n";  
                change =  gauss(temp) - (gauss(last.second - i + 1));
                
                res += change;
                last.first = i; last.second = j;
        }else{ 
                //cout << "res += gauss(" << j - i + 1 << ") i: " << i << "j: " << j << " \n";
                
                change = gauss(j-i + 1);
                
                res +=change ;
                last.first = i; last.second = j;
               
        }
        
    }else{
        contador[a[i]]--; if (contador[a[i]]==0){ contador.erase(a[i]);} 
        i++ ;  
        contador[a[j]]--;if(contador[a[j]] == 0) contador.erase(a[j]);j--;
    }
   /*cout << " i: " << i << "j: " << j << " \n";
    cout << "change :" << change << " res :" << res;
     cout << "\n" << "\n";*/
     
}
// cout << "el last second es:" << last.second << "\n ";
// cout <<  "el i es" << i << "\n";

cout << res;
}

