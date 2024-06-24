#include <bits/stdc++.h>
#define SI ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
int main(){
    SI
    long long n;
    cin >> n;
    if(n % 4 == 0){
        cout << "YES" << endl;
        cout << n/2 << endl;
        
        for(int i = 1; i <= n/4;i++){
            cout << i << " ";
        }
        for(int i = n - n/4 + 1;i <=n;i++ ){
            cout << i << " ";
        }
        cout << endl;
        cout << n/2 << endl;
        
        for(int i = n/4 + 1;i<n/2;i++){
            cout << i << " ";
 
        }
         
        for(int i = n/2;i<= n-n/4;i++){
            cout << i << " ";
            
        }
    
    }else if(n % 4 == 3){
        cout << "YES" << endl;
        cout << n/2 + 1 << endl;
 
        cout << 1 << " "  << 2 << " ";
        for(int i = 1; i <= (n-3)/4;i++){
            cout << i + 3 << " ";
        }
        for(int i = n - ((n-3)/4 +3 ) + 1;i <=n-3;i++ ){
            cout << i + 3 << " ";
        }
        cout << endl;
        cout << n- n/2 - 1 << endl;
        cout << 3 << " ";
        for(int i = (n-3)/4 + 1;i<(n-3)/2;i++){
            cout << i + 3 << " ";
 
        }
         
        for(int i = (n-3)/2;i<= (n-3)-(n-3)/4;i++){
            cout << i + 3<< " ";
            
        }
    }else{
        cout << "NO";
    }
}
