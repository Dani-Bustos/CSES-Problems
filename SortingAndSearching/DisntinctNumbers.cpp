#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 

 
 
int main(){
    FIN
 
    int  n;
    cin >> n;
    int a[n];
    fore(i,0,n){
        cin >> a[i];
    }
    sort(a,a + n);

    int num = 1;
    fore(i,0,n-1){
       if(a[i] != a[i+1]){
        num++;
       }
    }
    cout << num;
}