#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll; 
using namespace std;
  
int main(){
    int n;
    cin >> n;
    long long songs[n];
    
    fore(i,0,n){
        cin >> songs[i];
        
    }
    
    set<ll> played;
    queue<ll> window;
    ll res = 1; ll actual = 1;
    played.insert(songs[0]);
    window.push(songs[0]);
    fore(i,1,n){
      window.push(songs[i]);
      if( played.find(songs[i]) == played.end()){
        
        played.insert(songs[i]);
         
          
      }else{
        
        ll element = window.front();
        if(element == songs[i]){
            window.pop();
        }else{
        
            while(element != songs[i]){
                played.erase(element);
                window.pop();
                element = window.front();

            }
            window.pop();
        }
      }
      actual = window.size();  
      res = max(actual,res);

    }
   cout << res;
}