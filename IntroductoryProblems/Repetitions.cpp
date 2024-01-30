
#include <bits/stdc++.h>

using namespace std;

#define fore(i,a,b) for(int i=a; i<b; i++)
typedef long long  ll;



int main(){
   
   string palabra;
   cin >> palabra;
   long long max = 1;
   long long actual = 0;
   char letra = palabra[0];
   for(int i = 0; i<palabra.size();i++){
       if(palabra[i] == letra){
        actual++;
       }else{
        actual = 1;
        letra = palabra[i];
       }
       
       if(actual > max){
        max = actual;
       }
   }

    cout << max;
 } 