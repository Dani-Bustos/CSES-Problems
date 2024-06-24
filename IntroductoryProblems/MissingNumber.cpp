
#include <bits/stdc++.h>

using namespace std;

#define fore(i,a,b) for(int i=a; i<b; i++)
typedef long long  ll;



int main(){
   long long n;
   cin >> n;
   int arreglo[n-1];
   int i = 0;
   while (i<n-1){
    cin >> arreglo[i];
    i++;
   }
   
   sort(arreglo ,arreglo + sizeof(arreglo)/sizeof(arreglo[0]));
   i = 1;
   //Buscamos linealmente el numero que falta
   if(arreglo[0] != 1){
    cout << 1;
   }else{
   
    while(i<n){
        if( arreglo[i-1] != arreglo[i]-1){
            cout << arreglo[i-1] + 1;
            i = n +1;
        }
        i++;
   }
   }

 
 } 