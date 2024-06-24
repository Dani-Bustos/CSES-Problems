#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std ;
typedef long long ll;
 
void solve(int n, string actual,set<string> &global, queue<char> &letras){
 if(actual.size() == n){
    global.insert(actual);
 }else{
   for(int i = 0; i<letras.size();i++){
     char letra = letras.front();
     letras.pop();
     actual.push_back(letra);
     solve(n,actual,global,letras);
     actual.pop_back();
     letras.push(letra);
 
   }
 }
}
 
int main(){
    string s;
    cin>>s;
    set<string> res;
    queue<char> letras;
    for(int i = 0; i< s.size();i++ ){
       letras.push(s[i]);
    }
    string actual;
    solve(s.size(),actual,res,letras);
    cout << res.size() << endl;
    for(auto x : res){
        cout << x << "\n";
    }
}
