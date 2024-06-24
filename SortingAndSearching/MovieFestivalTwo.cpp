#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
template <typename T> using indexed_set =  tree<T,\
            null_type, less<T>, rb_tree_tag,\
            tree_order_statistics_node_update>;


bool sortPorSegundo(pair<int,int> a , pair<int,int> b){
    if(a.second < b.second){
        return true;
    }else if(a.second > b.second){
        return false;
    }else if(a.first < b.first){
        return true;
    }else{
        return false;
    }
}
 

int main(){
 FIN
 ll n,k;
 cin >> n >> k;

 pair<ll,ll> arr[n];
 multiset<ll> pelisAct;
 fore(i,0,n){
    int a,b;
    cin >> a >> b;
    arr[i] = {a,b};
    
 }

sort(arr,arr + n,sortPorSegundo);
int res = 0;
fore(i,0,k){
    pelisAct.insert(0);
    //res += 1    ;
}  
fore(i,0,n){
    auto tempra = pelisAct.upper_bound(arr[i].first);
    
    if( tempra != begin(pelisAct)){
        tempra--;
        pelisAct.erase(tempra);
        pelisAct.insert(arr[i].second);
        res +=1;
    }

}

cout << res;
}