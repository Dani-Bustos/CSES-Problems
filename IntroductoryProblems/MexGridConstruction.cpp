#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = b; i >=a;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define LOG2(x) 31  - __builtin_clz(x)
const double PI = 3.141592653589793238462643;
typedef long long ll;

using namespace std;

const int MAXN = 101;
int mat[MAXN][MAXN];
int n;
int firstValid(int col,int row){
    set<int> seen;
    fore(k,0,col){
        seen.insert(mat[row][k]);
    }
    fore(k,0,row) seen.insert(mat[k][col]);
    auto it = seen.begin();
    while(it != seen.end()){
        int val = *it;
        it++;
        if(it != seen.end()){
           int fwdVal = *it;
            if(fwdVal-val > 1) return val +1;

        }
        
    }
    if(seen.empty()) return 0;
    auto it2 = seen.end();
    it2--;
    int val =*it2;
    return val+1;
}


int main(){
    FAST_IO
    
    cin >> n;
    //La matriz es siempre simetrica, basta con que lo defina de la diagonal para abajo
    fore(i,0,n){
        fore(j,0,i+1){
            if(i == j) mat[i][j] = 0;
            else{
                mat[i][j] = firstValid(j,i);
                //Uso la simetria
                mat[j][i] = mat[i][j];
            }
        }
    }
    
    fore(i,0,n){
        fore(j,0,n){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    

}   

