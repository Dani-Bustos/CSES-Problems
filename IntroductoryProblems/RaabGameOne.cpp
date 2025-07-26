#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = b; i >=a;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define LOG2(x) 31  - __builtin_clz(x)
const double PI = 3.141592653589793238462643;
typedef long long ll;

using namespace std;

const int MAXN = 101;

int n,a,b;
int main(){
    FAST_IO
    
   int t_case;
   cin >> t_case;
   while(t_case--){
        cin >> n >> a >> b;

        int cantEmpates = n-a-b;
        if(cantEmpates > n){ 
            cout << "NO\n"; 
            continue;
        }

        vector<vector<int>> plays(2,vector<int>(n));
        const int FST = 0; const int SND = 1;
        set<int> disponibles;
        iota(plays[FST].begin(),plays[FST].begin() + cantEmpates,1);
        fore(i,cantEmpates+1,n+1){
            disponibles.insert(i);
        }
        iota(plays[SND].begin(),plays[SND].end(),1);
        
        int i = cantEmpates-1;
        int currA = 0; int currB = 0;
        bool sePuede = true;
        while(i < n && sePuede){
            if(currA < a){
                auto it = disponibles.end();
                it--;
                if(*it <= plays[SND][i]) sePuede = false;
                else{
                    plays[FST][i] = *it;
                    currA++;
                    disponibles.erase(it);
                }
            }
            else if(currB < b){
                auto it = disponibles.lower_bound(plays[SND][i]);
                if(it == disponibles.begin()) sePuede = false;
                else{
                    it--;
                    plays[FST][i] = *it;
                    currB++;
                    disponibles.erase(it);
                }
            }else{
                sePuede = false;
            }
            i++;
        }
        
        if(not sePuede) cout << "NO\n";
        else{
            fore(i,0,n) cout << plays[FST][i] << " ";
            cout<< "\n";
            fore(i,0,n) cout << plays[SND][i] << " ";
            cout << "\n";
        }

       

    
        
        


   }
    

}   

