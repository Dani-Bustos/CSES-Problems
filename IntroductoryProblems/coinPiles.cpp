#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(x) (int)x.size()
#define fst first
#define snd second 
#define all(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     
using namespace std;
typedef long long ll;
 
int main(){
    FIN
    ll t;
    cin >> t;
    fore(i,0,t){
        ll a,b;
        cin >> a >> b;
        if((a == 0 && b != 0 )|| (a != 0 && b== 0 )){
            cout << "NO" << endl;
        }
        else if( ((2*a - b) % 3 == 0) && ((2*b - a) % 3 == 0) && ((2*a - b) >= 0) && ((2*b - a)  >= 0)){
            cout << "YES" << endl;
 
        }else{
            cout << "NO" << endl;
        }
    }
}