#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<(int)b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std ;
typedef long long ll;
const ll MOD = 1e9 + 7;
using matrix = vector<vector<ll>>;
matrix matProd(matrix &A,matrix &B){
  matrix C(A.size(),vector<ll>(B[0].size(),0));
  fore(i,0,A.size()){
    fore(j,0,B[0].size()){
      fore(k,0,A[0].size()){
        C[i][j] = (C[i][j] + (A[i][k]*B[k][j] % MOD)) % MOD;
      }
    }
  }
  return C;
}

matrix fstMatExp4x4(matrix &M,ll b){
  if(b == 0) return {{1,0},{0,1}};
  if(b == 1) return M;
  vector<vector<ll>> half = fstMatExp4x4(M,b/2);
  matrix halfTimesHalf = matProd(half,half);
  if(b % 2 == 0) return halfTimesHalf;
  return matProd(halfTimesHalf,M);
}
pair<ll,ll> vecMatProd(matrix &A, pair<ll,ll>  &v){
    ll x = (A[0][0]*v.first % MOD + A[0][1]*v.second % MOD) % MOD;
    ll y = (A[1][0]*v.first  % MOD+ A[1][1]*v.second% MOD) % MOD;
    return {x,y};
}



//Idea: Notar que vale [F_n ] = [1  1][F_n-1] 
//                     [F_n-1]  [1  0][F_n-2]
//la relacion se matiene recursivamente, entonces 
//  [F_n  ]  = [1 1]^(n-1) *[F_1]
//  [F_n-1]    [1 0]        [F_0]
//Podemos usar divide and conquer para obtener la exponenciacion en O(log(n))
//Uso esta misma técnica en counting towers, cualquie recurrencia de esta pinta puede usar esta técnica
int main(){
    ll n;
    cin >> n;
    
    if(n == 0) cout << 0;
    else {
        matrix fibMat = {{1,1},{1,0}};
        pair<ll,ll> v_0 = {1,0};
        matrix n_mat = fstMatExp4x4(fibMat,n-1);
        cout << vecMatProd(n_mat,v_0).first;
    }   
}
