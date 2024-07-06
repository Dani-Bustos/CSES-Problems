#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)
typedef long long ll ;
const ll INF = 1e15;
int n, m;


vector<vector<char>> mat;

struct Node{
    int x,y,lvl;
    Node(int y_, int x_, int lvl_){
        x = x_ ; y = y_;lvl = lvl_;
    }
};

bool isValid(int y, int x){
    //Capaz que hay que pedir que no sea monstruo
    return (x != m && x != -1 && y != n && y != -1 && mat[y][x] != '#');
}


bool esBorde(int i,int j){
    return (j == 0 || j == m - 1) || (i == 0 || i == n -1);
}

int main(){
   
    cin >> n >> m;
    mat.resize(n,vector<char>(m));
    
    vector<pair<int,int>> bordes;
    char temp;
    vector<pair<int,int>> monstruos;
    pair<int,int> start;
   
    fore(i,0,n){
        fore(j,0,m){
            cin >> temp;
            mat[i][j] = temp;
            if(esBorde(i,j) && temp == '.') {
                bordes.push_back({i,j});
            }else if(temp == 'M') monstruos.push_back({i,j});
            else if(temp == 'A') start = {i,j};

        }
       
    }
    
    vector<vector<int>> D(n,vector<int>(m)); vector<vector<pair<int,int>> > P(n,vector<pair<int,int>>(m));
    //BFS desde el inicio a todos
    D[start.first][start.second] = 0;
    queue<Node> q;
    Node inicio(start.first,start.second,0);
    q.push(inicio);
    while(!q.empty()){
        Node act = q.front(); q.pop();
        //Abajo
        if(isValid(act.y + 1,act.x) && D[act.y + 1][act.x]){
            D[act.y + 1][act.x] = act.lvl + 1;
            P[act.y + 1][act.x] = {act.y,act.x};
            q.push(Node(act.y+1,act.x, act.lvl + 1));
        }
        //Arriba
        if(isValid(act.y -1 ,act.x) && D[act.y - 1][act.x]){
            D[act.y - 1][act.x] = act.lvl + 1;
            P[act.y - 1][act.x] = {act.y,act.x};
            q.push(Node(act.y-1,act.x, act.lvl + 1));
        }
        //Derecha
        if(isValid(act.y ,act.x + 1) && D[act.y][act.x + 1]){
            D[act.y ][act.x + 1] = act.lvl + 1;
            P[act.y ][act.x + 1] = {act.y,act.x};
            q.push(Node(act.y,act.x + 1, act.lvl + 1));
        }
        //Izqueierda
        if(isValid(act.y,act.x -1) && D[act.y ][act.x-1]){
            D[act.y ][act.x - 1] = act.lvl + 1;
             P[act.y ][act.x - 1] = {act.y,act.x};
            q.push(Node(act.y,act.x - 1, act.lvl + 1));
        }

    }
    //BFS desde el super monstruo
    vector<vector<int>> M(n,vector<int>(m));
    


}