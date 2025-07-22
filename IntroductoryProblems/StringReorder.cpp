#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = b; i >=a;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define LOG2(x) 31  - __builtin_clz(x)
const double PI = 3.141592653589793238462643;
typedef long long ll;

using namespace std;




int n,q;
int main(){
    FAST_IO
    string s;
    cin >> s;
    int n = s.size();
    string ans;
    sort(s.begin(),s.end());
    fore(i,0,s.size()-1){
        if(s[i] == s[i+1]){
            if(i == s.size()-2){ 
                cout << -1; 
                return 0 ;
            }
            else swap(s[i+1],s[i+2]);
        }
    }
    cout << s;
}   

