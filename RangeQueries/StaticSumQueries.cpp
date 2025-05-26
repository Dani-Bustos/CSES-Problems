#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = a; i >= (int)b;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

typedef long long ll;

const int MAXNUM = 1e5+1;




int main(){
    FAST_IO
    int n,q; cin >> n >> q;
    vector<ll> pref(n+1);
    pref[0] = 0;
    ll temp;
    fore(i,1,n+1){ cin >> temp;pref[i] = pref[i-1] + temp;} 
    fore(i,0,q){
        int a ,b;
        cin >> a >> b;
        cout << pref[b]- pref[a-1] << "\n";
        
    }



}



