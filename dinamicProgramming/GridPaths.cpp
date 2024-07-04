#include<bits/stdc++.h>

#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;

typedef long long ll;
ll MOD = 1e9 + 7;
const ll INDEF = -1;
int n;
vector<vector<long long>> memo(1002,vector<long long>(1002,INDEF));
vector<vector<char>> grid(1002,vector<char>(1002));
bool isValid(int i , int j){
    if(i >= 0 && i < n && j >= 0 && j < n && grid[i][j] != '*') return true;
    return false;
}

long long solve(int i,int j){
   if(i == n-1 && j == n - 1) return 1;
   if(memo[i][j] != INDEF) return memo[i][j];

    long long res = 0;
    if(isValid(i+1,j)) res += solve(i+1,j) % MOD;
    if(isValid(i,j+1)) res += solve(i,j+1) % MOD;
    memo[i][j] = res % MOD ;
    return memo[i][j];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    fore(i,0,n){
        fore(j,0,n){
            cin >> grid[i][j];
        }
    }
    if(isValid(0,0)) cout << solve(0,0);
    else cout << 0;
    

}


