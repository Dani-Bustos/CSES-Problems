#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

char moves[48];
int tablero[7][7];
long long suma;
string posibles;
int borde = 6;
int cuadrados = (borde + 1)*(borde + 1);

void solve(int x, int y,int indice){
   
    //cout << "(" << x << "," << y << ")" << "\n"; 
    if(indice == cuadrados -1 ){
        if(x == 0 && y == 0){
            suma+= 1; 
            //cout << "exito" << "\n";
            return;
        }else{
             return;
        }
    //si ya pasaste por el final para
    }else if(x == 0 && y == 0 && indice < cuadrados-1){
        //cout << "corte 1" << endl;
        return;
    //Si es no podes avanzar pero si a los costados para
    
    }else if( (y == borde  || y == 0  ||  ( tablero[x][y-1] == 1 && tablero[x][y+1] == 1 ) ) && (x > 0 && tablero[x-1][y] == 0 && x < borde && tablero[x+1][y] == 0)){
         //cout << "corte 2 arriba a" << "\n";
         return;
    

    }else if( (x == 0  || x  == borde  || ( tablero[x-1][y] == 1 &&  tablero[x+1][y] == 1 ) )&&(y > 0 && tablero[x][y-1] == 0 && y < borde && tablero[x][y+1] == 0) ){
     //cout << "corte 2 izquierda derecha" << "\n";
     return;
     }else if(moves[indice] == '?'){   
        fore(i,0,4){
            if(posibles[i] == 'U'){
                    
                 if( y < borde  && tablero[x][y+1] == 0){
                        tablero[x][y+1] = 1;
                       
                        solve(x,y+1,indice + 1);
                        tablero[x][y+1] = 0;
                        
                        
                    }
            }else if(posibles[i] == 'R'){
                    if( x < borde  && tablero[x+1][y] == 0){
                        tablero[x+1][y] = 1;
                        
                        solve(x+1,y,indice + 1);
                        tablero[x+1][y] = 0;
                        
                        
                    }
            }else if(posibles[i] == 'D'){
                    if (y > 0 && tablero[x][y-1] == 0){
                        
                        tablero[x][y-1] = 1;
                        
                        solve(x,y-1,indice + 1);
                        tablero[x][y-1] = 0;
                        
                    
                    }
            }else if(posibles[i] == 'L'){
                    if( x >  0 &&  tablero[x-1][y] == 0){
                        tablero[x-1][y] = 1;
                       
                        solve(x-1, y ,indice + 1);
                        tablero[x-1][y] = 0;
                                              
                    }
                }
        }     
        }else{
            if(moves[indice] == 'U'){
                    
                 
                    if( y < borde  && tablero[x][y+1] == 0){
                        tablero[x][y+1] = 1;
                        
                        solve(x,y+1,indice + 1);
                        tablero[x][y+1] = 0;
                        
                        
                    }
            }else if(moves[indice] == 'R'){
                    if( x < borde  && tablero[x+1][y] == 0){
                        tablero[x+1][y] = 1;
                       
                        solve(x+1,y,indice + 1);
                        tablero[x+1][y] = 0;
                        
                        
                    }
            }else if(moves[indice] == 'D'){
                    if (y > 0 && tablero[x][y-1] == 0){
                        
                        tablero[x][y-1] = 1;
                        
                        solve(x,y-1,indice + 1);
                        tablero[x][y-1] = 0;
                       
                    
                    }
            }else if(moves[indice] == 'L'){
                    if( x >  0 &&  tablero[x-1][y] == 0){
                        tablero[x-1][y] = 1;
                    
                        solve(x-1, y ,indice + 1);
                        tablero[x-1][y] = 0;
                                               
                    }
                }
            return;
        }   
    }


int main(){
    FIN

    fore(i,0,48){
        cin >> moves[i]; 
    }
    suma = 0;
    posibles = "DRLU";
   
    tablero[0][6] = 1;
   
    solve(0,6,0);
    
    cout << suma;
}