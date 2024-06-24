#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll; 
using namespace std;
 
 
 
int main(){
    FIN
    int n,x;
    cin >> x >> n;
    int a[n];
    int res[n];
    set<int> cortes;
    cortes.insert(0);
    cortes.insert(x);
    
   fore(i,0,n){
    cin >> a[i];
    cortes.insert(a[i]);
   }
    
    int maximo = 0;
    set<int>::iterator itr = cortes.begin();
    int previo = *itr;
    itr++;
    while(itr != cortes.end()){
    
        int actual = *itr - (previo);
     
            
        maximo = max(actual,maximo);
        previo = *itr;
        itr++;
    }
    
    res[n-1] = maximo; //rtas las voy calculando en reversa
    pair<int,int>  act;
    for(int i = n-2; i >= 0;i--){
        auto elem = cortes.find(a[i+1]);
        
        elem--;
        act.first = *elem; 
        elem++;elem++;
        act.second = *elem;
        elem--;

        if(act.second - (act.first) > maximo){
            res[i] = act.second - act.first;
            maximo = act.second - act.first;
        }else{
            res[i] = maximo;
        }
        cortes.erase(elem);
    }

    fore(i,0,n){
        cout << res[i] << " ";
    }
}