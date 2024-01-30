#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std ;
typedef long long ll;
void solve(int i, vector<string> &aCopiar,int n){
    if(i == n){
        return;
    }else{
        for(int j = pow(2,i);j>0;j-- ){
            string copia = aCopiar[j-1];
            copia[i] = '1';
            cout << copia << "\n";
            aCopiar.push_back(copia);
        }
        solve(i + 1,aCopiar,n);
    }
}
 
int main(){
    int n;
    cin>>n;
    string actual;
    string s1,s2;
    s1 = '0';
    s2 = '1';
    fore(i,1,n){
        s1.push_back('0');
        s2.push_back('0');
    }
    cout << s1 << endl;
    cout << s2 << endl;
    vector<string> res;
    res.push_back(s1);
    res.push_back(s2);
    solve(1,res,n);
}