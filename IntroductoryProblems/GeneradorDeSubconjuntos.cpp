#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> startUp(int n){
    vector<vector<int>> subConj(pow(2,n));
    vector<int> actual(0);
    GeneraSubconjuntos(1,n,subConj,actual);
    return subConj;

}

void GeneraSubconjuntos(int i, int n, vector<vector<int>>& Subconjuntos, vector<int>& actual){
    if (i == n + 1){
        //Si ya pudimos "elegir" entre todos los numeros procesamos el que tenemos
        Subconjuntos.push_back(actual);
    }else{
    actual.push_back(i);
    //Elegimos ponerlo en el conjunto  y avanzar al siguiente numero
    GeneraSubconjuntos(i+1,n, Subconjuntos,actual);
    
    //Elegimos no ponerlo en el conjunto y avanzar al siguiente numero
    actual.pop_back();
    GeneraSubconjuntos(i+1, n ,Subconjuntos,actual);
    
    }

}
 
int main(){
    long long n;
    cin >> n;
    vector<vector<int>> res(0);
    vector<int> actual(0);
    GeneraSubconjuntos(1,n,res,actual);
    for(vector<int> sub : res){
        cout << "{";
        for(int elemento : sub){
            cout << "," << elemento;
        }
        cout << "} ";
    }
}