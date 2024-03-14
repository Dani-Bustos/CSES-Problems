#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;



ll nums[1001];
unordered_map<ll,vector<pair<int,int>>> parejas;
int main(){
    FIN
    ll n,x; 
    cin >> n >> x;
    fore(i,1,n+1){
        cin >> nums[i];
    }
    

    
    
    parejas.reserve(1001*1001);
    for(int i =1; i <=n ; i++){
        for(int j = 1;j <i;j++){
            ll psum = nums[i] + nums[j];
            if(psum >= x) continue;
            if(parejas.find(x-psum) != parejas.end()){
                
                for(pair<int,int> k : parejas[x-psum]){
                    
                    if(k.first != j && k.second != i && k.first != i && k.second != j){
                        cout << k.first  << " " << k.second  << " " << j  << " " << i ;
                        return 0;
                    }
                }
            }else parejas[psum].push_back({j,i});
            
        }
    }
    cout << "IMPOSSIBLE";
}   