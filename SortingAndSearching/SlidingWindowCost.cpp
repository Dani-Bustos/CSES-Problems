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


 

int main(){
 FIN
 ll n,k;
 cin >> n >> k;
 indexed_set<pair<int,int>> s;
 int a[n];
 fore(i,0,n){
    cin >> a[i];
 }
 fore(i,0,k){
     s.insert({a[i],i});
 }


 int fst = 0; int lst = k;
 fore(i,0,n-k+1){
     auto p = *s.find_by_order((s.size() / 2));
     int target = p.first;
     ll tmpRes = 0;
     // cout << "el target es " << target << "\n";
     for(auto k : s){
         
         tmpRes+= abs( target - k.first);
     }
     cout << tmpRes << " ";
     
     s.erase({a[fst],fst});
     fst++;
     s.insert({a[lst],lst});
     lst++;
 }
 
  
}