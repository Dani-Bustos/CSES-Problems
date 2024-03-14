#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;



int main(){
    //IDEA: De atras para adelante buscamos valores , mas chicos que x - 2(para que almenos haya dos 1)
    //una vez que llegamos, usamos el algoritmo de sum of two Values dentro del rango restante
    //para obtener los otros 2, simplemente buscando la resta entre x y el que ya tengo
    //si no es posible, probamos de vuelta con uno mas chico
    //Complejidad : O(n)*ComplejidadDeTwoValues = O(n**2)
    FIN
    int n,x;
    cin >> n >> x;
    multiset<int> dic;
    pair<int,int> a[n];
    fore(i,0,n){
        int temp;
        cin >> temp;
        a[i].first = temp;a[i].second = i;
        

    }    
    sort(a,a+n);
    int i = n-1;
    while(a[i].first >= x - 1 && i!= -1){
        i--;
    }
    if(i == -1 || n < 3){
        cout << "IMPOSSIBLE";
    }else{
        set<int> res;
        bool flag = false;
        while(not flag && i!= 1){
        
            ll busco = x-a[i].first;
            int fst =  0; int snd = i-1;
            while(not flag && fst != snd){
                int suma =  a[fst].first + a[snd].first;
                if(suma == busco){
                    res.insert(a[fst].second + 1);
                    res.insert(a[snd].second + 1); 
                    res.insert(a[i].second + 1);
                    flag = true;       
                }else if(suma > busco){
                snd--;
                }else if(suma < busco){
                fst++;
                }
            }
            if(not flag || fst == snd){
                i--;
            }
        
        }   
        if(i == 1){
            cout << "IMPOSSIBLE";

        }else{
            for(auto k : res){
                cout << k <<  " ";
            }
        }
    }
    
   
}  