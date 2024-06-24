#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for(int i = 0; i < t;i++){
        long long  a,b,c,d,e,f,g,h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        if((a-c)*(f-h) == (b-d)*(e-g)){
            cout << "YES" << endl;

        }else{
            cout << "NO" << endl;
        }
    }
}