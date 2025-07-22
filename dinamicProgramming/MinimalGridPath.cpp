#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = b; i >=a;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
const double PI = 3.141592653589793238462643;
typedef long long ll;

using namespace std;


const ll INF = (1e18)/2;

const double EPS = 1e-6;
const int INDEF = -1;
int n;
string s;
int main(){
    int t_case;
    /*cin >> t_case;
    while(t_case--){
        cin >> s;   
    }*/
   int n,m;
   cin >> n;
   vector<vector<char>> mat(n,vector<char>(n));
   fore(i,0,n) fore(j,0,n) cin >> mat[i][j];
    ll dp[n+1][n+1];
   dp[0][0] = 0;
   
   map<char,int> cost;
   fore(i,0,26) cost['A'+i] = i;
   
   dfore(i,0,n-1){ 
    dfore(j,0,n-1){ 
        if(j == n-1 && i == n-1) dp[i][j] = cost[mat[i][j]];
        else dp[i][j] =  cost[mat[i][j]] + min( i < n-1 ? dp[i+1][j]: INF,
            j < n-1? dp[i][j+1] : INF);
        }
    }
    ll tot = dp[0][0];
    ll curr = 0;
    int x = 0;
    int y = 0;
    string ans; ans.push_back(mat[0][0]);
    curr = cost[mat[0][0]];
    fore(i,0,2*(n-1)){
        if(dp[x+1][y]  + curr == tot){
            x = x+1;
           
        }else{
            y = y+1;
        }
        curr += cost[mat[x][y]];
        ans.push_back(mat[x][y]);
    }
    cout << ans;

}   

