#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = b; i >=a;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define LOG2(x) 31  - __builtin_clz(x)
const double PI = 3.141592653589793238462643;
typedef long long ll;

using namespace std;

const int MAXN = 501;
const int MAXM = 501;
char MAT[MAXN][MAXM];
vector<vector<bool>> seen(MAXN,vector<bool>(MAXM,false));
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char even[2] = {'A','B'};
char odd[2] = {'C','D'};
map<char,int> toPos = {{'A',0},{'B',1},{'C',0},{'D',1}};
char nextRepresenante(int x, int y,bool parity){
    int ind = (toPos[MAT[y][x]] +1) % 2;
    if(parity) return even[ind];
    else return odd[ind];
}
int isValid(int x , int y){
    return x>= 0 && x < m && y>=0 && y < n;
}
//Es bipartito siempre existe un dos coloreo que respete
//ademas debo cambiar para que no sea la misma letra original, pero siempre se puede hacer
void color(){
    queue<pair<pair<int,int>,bool>> q;
    bool initialParity;
    if(MAT[0][0] == 'A' || MAT[0][0] == 'B') initialParity = true;
    else initialParity = false;
    q.push({{0,0},initialParity});
    seen[0][0] = true;
    
    while(not q.empty()){
        int x,y; tie(x,y) = q.front().first;
        bool parity = q.front().second;
        q.pop();
        MAT[y][x] = nextRepresenante(x,y,parity);
        fore(i,0,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx,ny) && not seen[ny][nx]){
                seen[ny][nx] = true;
                q.push({{nx,ny},not parity});

            }
        }
    }


}
int main(){
    FAST_IO
    
   cin >> n >> m;
   fore(i,0,n) fore(j,0,m) cin >> MAT[i][j];

   color();
   fore(i,0,n){
    fore(j,0,m){
        cout << MAT[i][j]   ;
        
    }
    cout << "\n";
  }
   

    
        
        


   
    

}   

