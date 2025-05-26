#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = a; i >= (int)b;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const ll INF = 1e18;  

typedef long long ll;


int main(){
    FAST_IO
    int n; cin >> n;
    vector<pair<int,int>> nums(n);
    
    int temp;
    fore(i,0,n){ cin >> temp; nums[i] = {temp,i};}
    sort(nums.begin(),nums.end());

    
   



}



