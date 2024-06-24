#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(x) (int)x.size()
#define fst first
#define snd second 
#define all(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     
using namespace std;
typedef long long ll;
 
int main(){
    FIN
    string s; cin>>s;
    
    int total = 0;
    
    
    map <char,int> reps;
    
    for(char letra:s){
         reps[letra]++;
        total++;   
    }
    map<char,int> :: iterator it;
    string primeraParte,segundaParte;
    char res[total];
    int dondeTamos = 0;
    if(total % 2 == 0){
        for( it = reps.begin(); it!= reps.end();it++){
            int numRep = it->second;
            if(numRep % 2 == 1){
              cout << "NO SOLUTION";
              return 0;
            }else{
                for(int i = 0; i<numRep/2;i++){
                    char letra = it->first;
                    res[dondeTamos] = letra;
                    res[total-1 - dondeTamos] = letra;
                    dondeTamos++;
                    
                }
            }
        }
       
    }
    else{
       char Impar = '0';
       for( it = reps.begin(); it!= reps.end();it++){
            int numRep = it->second;
            
            if(numRep % 2 == 1 ){
              if(Impar != '0'){
                cout << "NO SOLUTION";
                return 0;}else{
                    Impar = it-> first;
                }
            }
            for(int i = 0; i<numRep/2;i++){
                    char letra = it->first;
                    
                    res[dondeTamos] = letra;
                    res[total-1 - dondeTamos] = letra;
                    dondeTamos++;
                }
        }
             res[total/2] = Impar; 
    }
    string palabra;
    fore(i,0,total){
        palabra.push_back(res[i]);
    }
    cout << palabra; 
}