#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
typedef long long ll;
 
int fil[8];
int col[8];
int d1[15];
int d2[15];
int tablero[8][8];
int suma = 0;
void solve(int y , int n ){
 if(y == 8){
    suma++;
    return;
 }else{
    fore(x,0,8){
     if(col[x] == 0 && d1[x+y] == 0 && d2[x-y +7] == 0 && tablero[x][y] == 0){
       col[x] = d1[x+y] = d2[x-y +7] = tablero[x][y] = 1;
       solve(y+1,n);
        col[x] = d1[x+y] = d2[x-y +7] = tablero[x][y] = 0; 
     }
    }
}
 
 
}
    
 
 
 
 
int main(){
 FIN
 
 for(int y = 0; y<8;y++){
    for(int x = 0; x < 8; x++){
        char act;
        cin >> act;
        if(act == '*'){tablero[y][x] = 1;}
    }
 }
 solve(0,8);
 cout << suma; 
 
}