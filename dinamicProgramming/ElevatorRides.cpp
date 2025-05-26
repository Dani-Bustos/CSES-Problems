    #include<bits/stdc++.h>
    typedef long long ll;
    #define fore(i,a,b) for(int i = a; i< (int)b;i++)
    #define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    using namespace std;

    typedef long long ll;
    const int MAXN = 20;
    const ll INDEF = -1;
    const int INF = 1e8;
    int n,x,w;
    pair<int,int> memo[1<<MAXN]; //Dado subcjto de personas Q, memo[Q] : = {menor cantidad de ascensores para llevarlos, menor peso posible del último ascensor}
    
    inline bool ithBit(int num,int i){
        return (1<<i) & num;
    }
    inline int toggleBit(int num,int i){
        return (1<<i)^num;
    }

    ll weights[MAXN];
    

   
    
    
    int main(){ 
        
       cin >> n >> x;
       memo[0] = make_pair(1,0);
       fore(i,0,n) cin >> weights[i];

       fore(q,1,(1<<n)){
            memo[q] = {INF,0};
            fore(i,0,n){
                if(ithBit(q,i)){
                    pair<int,int> lstBest = memo[toggleBit(q,i)];
                    //Si lo puedo encajar en el mejor anterior lo hago
                    if(lstBest.second + weights[i] <= x){
                        lstBest.second+= weights[i];
                    }else{
                        //Sino , creo un ascesnro nuevo
                        lstBest.first++;
                        lstBest.second = weights[i];
                    }
                    memo[q] = min(memo[q],lstBest);    
                }
                
            }
       }
       cout << memo[(1<<n)-1].first;
    }


