#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a ; i < b; i++) 
using namespace std;
vector<vector<bool>> visitados (1001,vector<bool>(1001,false));
vector<vector<char>> mat;
int n ,m;
int Xa,Xb,Ya,Yb;
vector<char> camino(vector<vector<pair<int,int>>> &padre);

bool valid(int Posy,int Posx){
    if( Posx > m-1 || Posx < 0) return false;
    if(Posy > n - 1 || Posy < 0) return false;
    if((mat[Posy][Posx] == '.' || mat[Posy][Posx] == 'B') && not visitados[Posy][Posx])  return true;
    return false;
}

vector<char> camino(vector<vector<pair<int,int>>> &padre, pair<int,int> start, pair<int,int> end) {
    vector<char> res;
    pair<int, int> v = end;

    while (v != start) {
        pair<int, int> parent = padre[v.first][v.second];
        
        // Determine direction of movement
        if (parent.first > v.first) {
            res.push_back('U'); // Move up
        } else if (parent.first < v.first) {
            res.push_back('D'); // Move down
        } else if (parent.second > v.second) {
            res.push_back('L'); // Move left
        } else if (parent.second < v.second) {
            res.push_back('R'); // Move right
        }

        v = parent; // Move to the parent
    }

    // Reverse the result to get the correct order
    reverse(res.begin(), res.end());

    return res;
}

vector<char> bfs(int Ry,int Rx){
    visitados[Ry][Rx] = true;
    queue<pair<int,int>> q;
    vector<vector<pair<int,int>>> padre(n, vector<pair<int,int>> (m,{-1,-1}));
    q.push({Ry,Rx});
    while(!q.empty()){
        int y,x;
        tie(y,x) = q.front(); q.pop();
        if(y == Yb && x == Xb ){
            return camino(padre,{Ya,Xa},{Yb,Xb});
            
        }
        
        if(valid(y+1,x)){
            visitados[y+1][x] = true;
            padre[y+1][x] = {y,x};
            
            q.push({y+1,x});
        }
        if(valid(y-1,x)){ 
            visitados[y-1][x] = true;
            padre[y-1][x] = {y,x};
            q.push({y-1,x});
        }
        if(valid(y,x+1)){
            visitados[y][x+1] = true;
            padre[y][x+1] = {y,x};
            q.push({y,x+1});
        }
        if(valid(y,x-1)){ 
            visitados[y][x-1] = true;
            padre[y][x-1] = {y,x};
            q.push({y,x -1});
        }

    }
    vector<char> res(1,'A');
    return res;

}

vector<char> solve(){
    

    return bfs(Ya,Xa);
}



int main(){
    
    cin >> n >> m;
    mat.clear();
    mat.resize(n,vector<char>(m));

    
    fore(i,0,n){
        fore(j,0,m){
            cin >> mat[i][j];
            if(mat[i][j] == 'A'){
                Ya = i;
                Xa = j;
            }
            if(mat[i][j] == 'B'){
                Xb = j;
                Yb = i;
            }
        }
    }
    vector<char> res = solve();
    if(res[0] == 'A'){
        cout << "NO";
    }else{
        cout << "YES" << "\n";
        cout << res.size() << "\n";
        fore(i,0,res.size()){
            cout << res[i];
        }
    }



}