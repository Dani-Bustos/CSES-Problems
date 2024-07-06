#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)
typedef long long ll ;
const int INF = 1e9;
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
            else if(temp == 'A'){
                start = {i,j};
                if(esBorde(i,j)){ 
                    cout << "YES"; return 0;
                }
            }
             

        }
       
    }
    
    vector<vector<int>> D(n,vector<int>(m,INF)); vector<vector<pair<int,int>> > P(n,vector<pair<int,int>>(m));
    
    P[start.first][start.second] = start;
   //BFS desde el inicio a todos
    D[start.first][start.second] = 0;
    queue<Node> q;
    Node inicio(start.first,start.second,0);
    q.push(inicio);
    while(!q.empty()){
        Node act = q.front(); q.pop();
        //Abajo
        if(isValid(act.y + 1,act.x) && D[act.y + 1][act.x] == INF){
            D[act.y + 1][act.x] = act.lvl + 1;
            P[act.y + 1][act.x] = {act.y,act.x};
            q.push(Node(act.y+1,act.x, act.lvl + 1));
        }
        //Arriba
        if(isValid(act.y -1 ,act.x) && D[act.y - 1][act.x] == INF){
            D[act.y - 1][act.x] = act.lvl + 1;
            P[act.y - 1][act.x] = {act.y,act.x};
            q.push(Node(act.y-1,act.x, act.lvl + 1));
        }
        //Derecha
        if(isValid(act.y ,act.x + 1) && D[act.y][act.x + 1] == INF){
            D[act.y ][act.x + 1] = act.lvl + 1;
            P[act.y ][act.x + 1] = {act.y,act.x};
            q.push(Node(act.y,act.x + 1, act.lvl + 1));
        }
        //Izquerda
        if(isValid(act.y,act.x -1) && D[act.y ][act.x-1] == INF){
            D[act.y ][act.x - 1] = act.lvl + 1;
            P[act.y ][act.x - 1] = {act.y,act.x};
            q.push(Node(act.y,act.x - 1, act.lvl + 1));
        }

    }
    //BFS desde el super monstruo
    vector<vector<int>> M(n,vector<int>(m,INF));
    //Ponemos a todos los monstruos con distancia 0, como si la bfs hubiese empezado desde un nodo fantasma
    fore(i,0,monstruos.size()){
        int m_i = monstruos[i].first;
        int m_j = monstruos[i].second;
        M[m_i][m_j] = 0;
        q.push(Node(m_i,m_j,0));
       
    }
    
    while(!q.empty()){
        Node act = q.front(); q.pop();
        //Abajo
        if(isValid(act.y + 1,act.x) && M[act.y + 1][act.x] == INF){
            M[act.y + 1][act.x] = act.lvl + 1;
            
            q.push(Node(act.y+1,act.x, act.lvl + 1));
        }
        //Arriba
        if(isValid(act.y -1 ,act.x) && M[act.y - 1][act.x] == INF){
            M[act.y - 1][act.x] = act.lvl + 1;
            
            q.push(Node(act.y-1,act.x, act.lvl + 1));
        }
        //Derecha
        if(isValid(act.y ,act.x + 1) && M[act.y][act.x + 1] == INF){
            M[act.y ][act.x + 1] = act.lvl + 1;
            
            q.push(Node(act.y,act.x + 1, act.lvl + 1));
        }
        //Izquerda
        if(isValid(act.y,act.x -1) && M[act.y ][act.x-1] == INF){
            M[act.y ][act.x - 1] = act.lvl + 1;
            
            q.push(Node(act.y,act.x - 1, act.lvl + 1));
        }
        
        
    }


    //Nos fijamos si la distancia a alguna salida es menor que la de los monstruos
    vector<char> path;
    fore(i,0,bordes.size()){
        int sX,sY; tie(sY,sX) = bordes[i];
        //Reconstruimos el camino
        if(D[sY][sX] < M[sY][sX]){
            cout << "YES" << "\n";
            for( pair<int,int> v = {sY,sX}; v != P[v.first][v.second]; v = P[v.first][v.second]){
                //Bajo
                if(P[v.first][v.second].first < v.first) path.push_back('D');
                //Subio
                if(P[v.first][v.second].first > v.first) path.push_back('U');
                //Derecha
                if(P[v.first][v.second].second < v.second) path.push_back('R');
                //Izquierda
                if(P[v.first][v.second].second > v.second) path.push_back('L');

            }
            cout << path.size() << "\n";
            reverse(path.begin(),path.end());

            for(char Letra : path){
                cout << Letra;
            }
            return 0;
        }
    }
    cout << "NO";
}