#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll; 
using namespace std;
 
int INF = 2*pow(10,6);
struct Tripla{
    int prev;
    ll num;
    int sig;
};
 
 
int main(){
    FIN
    int n,m;
    cin >> n >> m;
    pair<long long,int> numeros[n];
    
    fore(i,0,n){
        cin >> numeros[i].first;
        numeros[i].second = i;
    }
    sort(numeros,numeros + n);  
 
    int rondas = 1;
    fore(i,1,n){
        if(numeros[i-1].second > numeros[i].second){
         rondas = rondas + 1;   
        }
    }
    //Hasta aca n + n*logn
    Tripla simulation[n];
     
        
    fore(i,0,n){
        int pos = numeros[i].second;
        simulation[pos].num = numeros[i].first;
        
        if(numeros[i].first == 1){
           simulation[pos].prev = -1; 
           simulation[pos].sig = numeros[numeros[i].first -1 + 1].second;
        }else if(numeros[i].first == n){
            simulation[pos].sig = INF; 
            simulation[pos].prev = numeros[numeros[i].first -1 - 1].second;
        }else{
            simulation[pos].prev = numeros[numeros[i].first -1 - 1].second;
            simulation[pos].sig = numeros[numeros[i].first -1 + 1].second;
        }
    }//Otra n    
   
    int a , b;
    fore(y,0,m){
        
        cin >> a >> b;
        a--; b--;
        int stA = 0;    
        int stB = 0;
        int nstA = 0;
        int nstB = 0;

        
        
        if(b == simulation[a].sig){
            //Caso b es sucesor de a 
            if(b < a ){
                stB++;
            }
            if(a < simulation[a].prev ){
                stA++;
            }
            if(b > simulation[b].sig ){
                stB++;
            }   

            Tripla buffer = simulation[b];
            simulation[b] = simulation[a];
            simulation[a] = buffer;
            
            simulation[a].prev = b;
            simulation[b].sig = a;
            if(simulation[a].num != n){
                simulation[simulation[a].sig].prev = a;
            }
            if(simulation[b].num != 1){
                simulation[simulation[b].prev].sig = b;
            }

           if(b > a ){
                nstB++;
            }
            if(a > simulation[a].sig){
                nstA++;
            }
            if(b < simulation[b].prev ){
                nstB++;
            }   
         
 
        }else if( b == simulation[a].prev){
            //Caso b es previo de a
            if(b > a ){
                stB++;
            }
            if(a > simulation[a].sig ){
                stA++;
            }
            if(b < simulation[b].prev ){
                stB++;
            }   
            
            
            
            Tripla buffer = simulation[b];
            simulation[b] = simulation[a];
            simulation[a] = buffer;
            
            simulation[a].sig = b;
            simulation[b].prev = a;
            
            if(simulation[a].num != 1){
                simulation[simulation[a].prev].sig = a;
            }
            if(simulation[b].num != n){
                simulation[simulation[b].sig].prev = b;
            }
           


            if(b < a ){
                nstB++;
            }
            if(a < simulation[a].prev ){
                nstA++;
            }
            if(b > simulation[b].sig ){
                nstB++;
            }   


        }else{
          if(a > simulation[a].sig ){
            stA++;
            }
          if(a < simulation[a].prev){
            stA++;
           }
 
          if(b > simulation[b].sig ){
            stB++;
          }
          if(b < simulation[b].prev){
            stB++;
          }
            
            
            Tripla buffer = simulation[b];
            simulation[b] = simulation[a];
            simulation[a] = buffer;
            //actualiza los indices de prev y sig
            if(simulation[a].num !=n ){
                simulation[simulation[a].sig].prev = a;
            }
            
            if(simulation[b].num != n ){
                simulation[simulation[b].sig].prev = b;
            }

            if(simulation[b].num != 1){
                simulation[simulation[b].prev].sig = b;
            }

            if(simulation[a].num != 1){
                simulation[simulation[a].prev].sig = a;
            }      
            
            
            if(a > simulation[a].sig ){
             nstA++;
            }
            if(a < simulation[a].prev){
                nstA++;
            }
 
            if(b > simulation[b].sig ){
                nstB++;
            }
            if(b < simulation[b].prev){
                nstB++;
            }
        }
        int totalStatus = stA + stB;
        
        
        
    
        int change = (nstB + nstA) - totalStatus;
        rondas += change;
        cout << rondas << "\n";
    }
    
}