#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)
using namespace std;
vector<long long> S;
const int INF = 1e9;
int n,a,b;
vector<int> memo(1e6+2,-1);

int i_thDigit(int i,int num){
   return (num/(int) pow(10,i)) % 10;
}
int solve(int num){
   if(num < 0) return INF;
   if(num == 0) return 0;
   if(memo[num]!= -1) return memo[num];
   int res = INF;
   fore(i,0,(int)log(num)){
    int aRestar = i_thDigit(i,num);
    if(aRestar != 0)res = min(res,1 + solve(num - aRestar));
   }
    memo[num] = res;
    return memo[num];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    
    cout << solve(n);
    

}


