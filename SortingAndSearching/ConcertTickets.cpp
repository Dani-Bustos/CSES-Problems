#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;


 
 
int main(){
    FIN
    int numTickets,numClientes;
    cin >> numTickets >> numClientes;
    multiset<int> t;
    int c[numClientes];
    
    fore(i,0,numTickets+numClientes){

       if(i < numTickets){
        int temp ;
        cin >> temp;
        t.insert(temp);
       }else{
        cin >> c[i-numTickets];
       }  
    }
    
    
    int i = 0; 
    bool outeaste = false;
    multiset<int>::iterator actual;
    while(i<numClientes && t.size() != 0){
        outeaste = false;
        actual = t.lower_bound(c[i]);
        auto ultimo = t.rbegin();
        
        if(*ultimo < c[i]){
        
          cout << *ultimo << '\n';
         
          t.erase(prev(t.end()));
        }
       else if(*actual == c[i]){
            cout << *actual << "\n";
            t.erase(actual);
            
        }else{
            while( actual != t.begin() && *actual > c[i]){
                actual--;
                if(*actual < c[i]){
                        cout << *actual << "\n";
                        outeaste = true;
                        t.erase(actual);
                        break;
                }
            }
            
            if((actual == t.begin() || t.size() == 0) && outeaste == false){
                
                cout << -1 << "\n";
            }
                
            }
        i++;
    }  
    while(i< numClientes){
        cout << -1 << "\n";
        i++;
    }
}
