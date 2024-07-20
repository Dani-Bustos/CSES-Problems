#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)
using namespace std;
vector<long long> S;
int n,a,b;
int solve(){
    int i,j; i = 0;j = b - a;
    long long best =0;
    
    while(i <= n){
        if( j - i <= b && a <= j - i){
            best = max(best,S[j]-S[i]);       
        }
        
        
    }   
    return best;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> a >> b;
    S.resize(n+1);
    S[0] = 0;
    fore(i,1,n+1){
        int temp;
        cin >> temp;
        if(i !=0) S[i] = temp + S[i-1];
    }
    cout << solve();

    

}


