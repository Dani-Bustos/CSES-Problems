#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)
using namespace std;
vector<long long> S;
int n,a,b;
int solve(){
    int i,j; i = 0; j  = (a-2;
    long long best =0;
   
    while(i != n){
        best = max(best,i < 0 ? S[j]- S[i-1]: S[j]);
        
        if(j - i +1< b && j < n)j++;
        else if(j-i + 1 > a)i++;
        else break;
    }   
    return best;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> a >> b;
    S.resize(n);

    fore(i,0,n){
        cin >> S[i];
        if(i !=0) S[i] +=S[i-1];
    }
    cout << solve();

    

}


