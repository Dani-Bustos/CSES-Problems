#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll; 
using namespace std;

 

int main(){
 FIN
 int n;
 cin >> n;
 set <int> s;
 fore(i,0,n){
  s.insert(i+1);
 }
    
 auto itr = s.begin();
 fore(i,0,n){
    itr++;
    if(itr == s.end()){
        itr = s.begin();
    }
    cout << *itr  << " ";
    itr = s.erase(itr);
    if(itr == s.end()){
        itr = s.begin();
    }
 }

}