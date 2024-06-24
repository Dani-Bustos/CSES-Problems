#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a ; i < b; i++) 
using namespace std;
vector<vector<bool>> visitados (1001,vector<bool>(1001,false));
vector<vector<char>> mat;
int n ,m;
 
 
bool valid(int Posy,int Posx){
    if( Posx > m-1 || Posx < 0) return false;
    if(Posy > n - 1 || Posy < 0) return false;
    if(mat[Posy][Posx] == '.' && not visitados[Posy][Posx])  return true;
    return false;
}
 
void dfs(int y,int x){
    visitados[y][x] = true;
    if(valid(y+1,x)){ 
        dfs(y+1,x);
    }
    if(valid(y-1,x)) {
        dfs(y-1,x);}
    if(valid(y,x+1)){ 
        dfs(y,x+1);}
    if(valid(y,x-1)) {
        dfs(y,x -1);}
    
 
}
 
int solve(){
    int compoConexas = 0;
    fore(i,0,n){
        fore(j,0,m){
            if(mat[i][j] == '.' && not visitados[i][j]){
                dfs(i,j);
                compoConexas++;
            }
        }
    }
 
    return compoConexas;
}
 
 
 
int main(){
    
    cin >> n >> m;
    mat.clear();
    mat.resize(n,vector<char>(m));
 
    
    fore(i,0,n){
        fore(j,0,m){
            cin >> mat[i][j];
            
        }
    }
 
    cout << solve();
 
 
 
}