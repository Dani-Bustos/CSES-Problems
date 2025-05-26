#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

typedef long long ll;

const int MAXNUM = 1e5+1;

int main(){
    FAST_IO
    //n <= 100, x_i <=1000, entonces la suma maxima que podremos hace en el peor caso  es 10^5
    int n;  cin >> n; 
    vector<int> nums(n);
    vector<vector<bool>> memo(n+1,vector<bool>(MAXNUM,false));
    
    fore(i,0,n) cin >> nums[i];
    
    //casos base
    fore(i,0,n+1) memo[i][0] = true;

    //dp bottom-up

    fore(i,1,n+1){
        fore(act,1,MAXNUM){
            
            if(act - nums[i-1] >= 0) memo[i][act] = memo[i-1][act] || memo[i-1][act-nums[i-1]];
            else memo[i][act] = memo[i-1][act];
        }
    }
    
    vector<int> posibles;
    fore(i,1,MAXNUM){
        if(memo[n][i]) posibles.push_back(i);
    }
    cout << posibles.size() << "\n";
    fore(i,0,posibles.size()) cout << posibles[i] << " ";
    

}



