#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll; 
//Idea : Separar en grupos a los mas grandes y los mas chicos de la media, ir actualizando inteligemente estos grupos  y tener un contador global de la suma de sus elementos
//despues simplemente los podes restar sus sumas entre si y te da el costo, poniendo o no la media segun la paridad en es cuenta


multiset<ll> masGrandes; ll grandes = 0;
multiset<ll> masChicos; ll chicos = 0;
int k;
void insertar(ll val){
    if (chicos == 0 && grandes == 0){
        masChicos.insert(val);
        chicos += val;
        return;
    }
    
    
    ll act = *masChicos.rbegin(); //ultimo elemento
    if( act < val){
        masGrandes.insert(val);
        grandes += val;
        if(masGrandes.size() > k/2){
            auto aMover = masGrandes.begin();
            masChicos.insert(*aMover);
            chicos +=  *aMover;
            masGrandes.erase(aMover);
            grandes -= *aMover;
        }
    }else{
        masChicos.insert(val);
        chicos +=val;
        if(masChicos.size() > (k+1)/2){//En los mas chicos metemos la mediana
            auto aMover = masChicos.rbegin();
            masGrandes.insert(*aMover);
            grandes += *aMover;
            chicos -= *aMover;
            masChicos.erase(masChicos.find(*aMover));
            
        } 
    }

}

void elim(ll valor){
    if(masGrandes.find(valor) != masGrandes.end()) grandes -= valor, masGrandes.erase(masGrandes.find(valor));
    else masChicos.erase(masChicos.find(valor)),chicos-= valor;
    if(masChicos.empty() && k != 1){   
        auto aMover = masGrandes.begin();
        masChicos.insert(*aMover);
        chicos +=  *aMover;
        masGrandes.erase(aMover);
        grandes -= *aMover;
    }
}

int main(){
 FIN
 int n;
 cin >> n >> k;
 
 int a[n];
 fore(i,0,n){ 
    cin >> a[i];
 }
 
 fore(i,0,k-1){
    insertar(a[i]);
 }
 
 fore(i,k-1,n){
     insertar(a[i]);
     ll costo;
     if (k% 2 == 1)  costo =  grandes + *masChicos.rbegin() - chicos ; 
     else costo = grandes - chicos ;
     cout << costo << " ";
     elim(a[i-k+1]);
     
          
 
 }
 
 
  
}