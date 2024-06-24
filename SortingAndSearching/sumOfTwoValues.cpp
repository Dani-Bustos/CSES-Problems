#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 

 
 
int main(){
    FIN
    int n,x;
    cin >> n >> x;
    multiset<int> dic;
    pair<int,int> a[n];
    fore(i,0,n){
        int temp;
        cin >> temp;
        a[i].first = temp;a[i].second = i;
        

    }
    
    sort(a,a+n);
    int i = 0;int j = n-1;
    bool flag = false;
    set<int> res;
    while(not flag && i != j){
        int suma = a[i].first + a[j].first;
        if(suma == x){
            res.insert(a[i].second + 1);
            res.insert(a[j].second + 1); 
            flag = true;       
        }else if(suma > x){
            j--;
        }else if(suma < x){
            i++;
        }
    }
   if(i == j){
    cout << "IMPOSSIBLE";
   }
   for(auto k : res){
    cout << k << " " ;
   }
}
