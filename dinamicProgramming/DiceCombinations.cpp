#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)

using namespace std;
const long long INDEF = -1;
vector<long long> MEMO;
long long solve(int target){
    if( target < 0){
        return 0;
    }
    else if(MEMO[target] != INDEF){ //caso base dado por la meme
        return MEMO[target];
    
    }else{
        long long sum = 0;
        fore(i,1,7){
             sum += solve(target-i);
        }
    
        MEMO[target] = sum;
    }
    return MEMO[target];

}

int main(){
    int n;
    cin >> n;
    MEMO.resize(n+1,INDEF);
    MEMO[0] = 1;
    cout << solve(n);

    
}
