#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 

 
 
int main(){
    FIN
    int numChildren,limite;
    cin >> numChildren >> limite;
    int pibes[numChildren];
    fore(i,0,numChildren){
        cin >> pibes[i];
    }
    sort(pibes,pibes + numChildren);
    int res = 0;
    int i = 0; int j = numChildren -1;
    bool flag = true;
    while( i < numChildren-1 && j >= 0 && i != j && flag){

        if(pibes[i] + pibes[j] <= limite){
            res++;
            i++;
            if(i == j){

                flag = false;
            }
            j--;
        }else{
            res++;
            j--;
        }
    }
    if(i == j){
        res++;
    }
    
    cout << res;

}