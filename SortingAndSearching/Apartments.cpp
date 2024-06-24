#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 

 
 
int main(){
    FIN
 
    int  gente,deptos,tol;
    cin >> gente >> deptos >> tol;
    int a[gente], b[deptos];
    fore(i,0,gente +    deptos){
        if(i<gente){
        cin >> a[i];
        }else{
            cin >> b[i-gente];
        }
    }
    
    
    int res = 0;
    sort(a,a+gente);sort(b,b+deptos);
    int i = 0;
    int j = 0;
    while(i < gente && j < deptos){
      long long dif = abs(a[i] - b[j]);
      if(dif <= tol){
        res++;i++;j++;
      }else if(a[i]<b[j]){
        i++;
      }else{
        j++;
      }
    }
   cout << res;
}
