#include <bits/stdc++.h>


using namespace std;


int main(){
    long long t;
    cin >> t;
    long long fila,columna;
    for(long long i = 0;i<t;i++){
        cin >> fila >> columna;
        //Caso diagonal
        if(fila == columna){
            cout << fila*columna - columna + 1 << "\n";
         } //Por encima de la diagonal
        else if (columna > fila){
            if(columna % 2 == 0){
                cout << columna*columna - columna + 1 - (columna - fila) << "\n";
            }else{
                cout << columna*columna  + 1  - fila << "\n";
            }
        } // Por debajo de la diagonal
        else{

            if(fila % 2 == 0){
                cout << fila*fila  + 1 - columna << "\n";
                
            }else{
                cout << fila*fila -fila + 1 - (fila -columna) << "\n";
            }
        }
    } 
}