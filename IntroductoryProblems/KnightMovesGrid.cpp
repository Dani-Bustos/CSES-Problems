#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = b; i >=a;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define LOG2(x) 31  - __builtin_clz(x)
const double PI = 3.141592653589793238462643;
typedef long long ll;

using namespace std;

const int MAXN = 1001;
const int INDEF = -1;
const ll INF = 1e18;
int n,a,b;
int dx[8] = {1,-1,-2,-2,-1,1,2,2};
int dy[8] = {2,2,1,-1,-2,-2,-1,1};
vector<vector<ll>> memo(MAXN,vector<ll>(MAXN,INDEF));
//Explotamos la simetra
pair<int,int> dominate(int x , int y){
   if(x>y) return {y,x};
   return {x,y};
}
inline bool isValid(int x,int y) {
    return 0 <= x && x <n && y>=0 && y <n;
}

void solve(){
    
    
    queue<pair<pair<int,int>,ll>> q;
    q.push({{0,0},0});
    
    while(not q.empty()){
        int x,y;
        tie(x,y) = q.front().first; 
        ll lvl = q.front().second;
        q.pop();
        fore(i,0,8){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //Simetria de las soluciones
            tie(nx,ny) =dominate(nx,ny);
            if(isValid(nx,ny) && memo[nx][ny] == INDEF){
                memo[nx][ny] = lvl+1;
                q.push({{nx,ny},lvl+1});
            }

        }
    }
    return;
}

int main(){
    FAST_IO
    
   cin >> n;
   memo[0][0] = 0;
  
   solve();
   
   fore(i,0,n){
    fore(j,0,n){
        int x,y; tie(x,y) = dominate(j,i);
        cout << memo[x][y] << " ";
    }
     cout << "\n";
    }

}   

