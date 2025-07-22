#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = b; i >=a;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define LOG2(x) 31  - __builtin_clz(x)
const double PI = 3.141592653589793238462643;
typedef long long ll;

using namespace std;


const ll INF = (1e18)/2;

const double EPS = 1e-6;
const int INDEF = -1;
int n;
map<pair<int,int>,ll> cache;
const int MAXN = (int)2*1e5 + 10;
const int MAXLOG = 21;
ll nums[MAXN];
ll table[MAXLOG][MAXN];
int K;

void generate_sparse_table(){
    fore(i,0,n) table[0][i] = nums[i];
    
    fore(i,1,K+1){
        
        for(int j = 0; j + (1<<i) <= n;j++){
            //min(i,i+2^h) = (min(min(i,i+2^(h-1)),min(i+2^(h-1),i + 2^(h))
            //en palabras, el minimo desde 0 hasta 0 + 8 es igual al minimo entre 0 + 4 y 4 + 8
            
            table[i][j]= min(table[i-1][j],table[i-1][j + (1<<(i-1))]);
        }

    }
}

ll min_in_range(unsigned int l, unsigned int r){
    unsigned int diff = LOG2(r-l);
    
    int powOfTwo = (1<<diff);
    //hay un poco de overlap entre esos rangos pero no pasa nada porque el minimo es idempotente
    return min(table[diff][l],table[diff][r-powOfTwo]);
}

int q;
int main(){
    FAST_IO
    cin >> n >> q;
    K = LOG2(n)+1;
    fore(i,0,n) cin >> nums[i];
    generate_sparse_table();
    while(q--){
        unsigned int a,b;
        cin >> a >> b;
        a--;b--;
        cout << min_in_range(a,b+1) << "\n";
    }

}   

