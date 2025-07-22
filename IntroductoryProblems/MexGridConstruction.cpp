#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = b; i >=a;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define LOG2(x) 31  - __builtin_clz(x)
const double PI = 3.141592653589793238462643;
typedef long long ll;

using namespace std;




int n,q;
int main(){
    FAST_IO
    int n;
    cin >> n;
    vector<set<int>> cols(n);
    vector<set<int>> rows(n);
    fore(i,0,n){
        fore(t,1,n*n +1){
            cols[i].insert(t);
            cols[j].insert()
        }
    }

    fore(i,0,n){
        fore(j,0,n){
            int toPut;
            if(cols[j] > rows[i]){
                toPut = cols[j];
                cols[j] = toPut+1;
                rows[i] = min(cols[j],rows[i]);
            }else{
                toPut = rows[i];
                
                rows[i] += 1;
                
                
            }
            cout << toPut << " ";
        }
        cout << "\n";
    }
    
    
    

}   

