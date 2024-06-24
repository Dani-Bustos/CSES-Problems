#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std ;
typedef long long ll;
int findRange (long long rangos[], long long num){ 
    int i = 0;
    while(i<18){
     if(num < rangos[i]){
        return i+1;
     }   
     i++;   
    }
    return i;
}
 
int main(){
    FIN
    long long preCalc[17];
    preCalc[0] = 9 + 1;
    fore(i,1,17){
        preCalc[i] = 9*(long long)pow(10,i)*(i+1) + preCalc[i-1];
    }   
    /*fore(i,0,17){
    cout << preCalc[i] << "\n";} */
    int t; cin >> t;
    fore(v,0,t){
       long long k;
       int res;
       cin >> k;
       int digitos = findRange(preCalc,k);
       if(digitos == 1){
        cout << k << "\n";}
       else{
            ll posnum;
       
            ll pos_num = k  - preCalc[digitos-2] ;
            if(pos_num < digitos){  
                if(pos_num == 0){
                res = 1;
                }else{res = 0;}
        
            }else{
            ll num = (long long) (pow(10,digitos - 1)) + pos_num/digitos;
            // cout << "n : " << num << "\n";
            int aObtener = pos_num % digitos;
            ll pot = (ll)pow(10,digitos-1 - aObtener);
            ll temp = num/pot;
            res = temp % 10;
 
        }
       cout << res << "\n";
    }
    }
        
}   