#include <bits/stdc++.h>
#define SI ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
int main(){
    SI
    long long n;
    cin >> n;
    long long res = 0;
    long long i = 1;
    while(n >= 5){
     n = n/5;
     res += n;
     
    }
    cout << res;
    }