#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 

 
 
int main(){
    int n;
    cin >> n;
    long long palitos[n];
    fore(i,0,n){
        cin >> palitos[i];
    }
    sort(palitos,palitos + n);
    long long media = palitos[n/2];
    long long res = 0;
    fore(i,0,n){
        res += abs(media-palitos[i]);
    }
    cout << res;
}
