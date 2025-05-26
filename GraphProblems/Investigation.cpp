#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< (int)b;i++)
#define dfore(i,a,b) for(int i = a; i >= (int)b;i--)
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e5+1;
const int INDEF = -1; const ll INF = 1e18;
vector<ll> memo(MAXN,INDEF);


struct Edge{
    int v,w; ll c;
    Edge(int a, int b, int costo): c(costo),v(a),w(b){}

    
};

struct digraph{
    vector<vector<pair<int,ll>>> ady;
    vector<vector<pair<int,ll>>> inAdy;
    digraph(int V){ady.resize(V), inAdy.resize(V);}

    void addEdge(int v,int w,ll c){
        ady[v].push_back({w,c});
        inAdy[w].push_back({v,c});
    }

    vector<ll> Djikstra(int source){
        vector<ll> dist(ady.size(),INF);
	    priority_queue<pair<ll,int> > q;
	    dist[source]=0;
        q.push({0,source});
        int x;
	    while(!q.empty()){
		    x=q.top().second;ll c=-q.top().first;q.pop();
		    if(dist[x]!=c)continue;
		    fore(i,0,ady[x].size()){
			    int y=ady[x][i].first; ll c=ady[x][i].second;
			    if(dist[y]<0||dist[x]+c<dist[y])
				    dist[y]=dist[x]+c,q.push({-dist[y],y});
		    }

        }
        return dist;
    }

    vector<ll> InDjikstra(int source){
        vector<ll> dist(inAdy.size(),INF);
	    priority_queue<pair<ll,int> > q;
	    dist[source]=0;
        q.push({0,source});
        int x;
	    while(!q.empty()){
		    x=q.top().second;ll c=-q.top().first;q.pop();
		    if(dist[x]!=c)continue;
		    fore(i,0,inAdy[x].size()){
			    int y=inAdy[x][i].first; ll c=inAdy[x][i].second;
			    if(dist[y]<0||dist[x]+c<dist[y])
				    dist[y]=dist[x]+c,q.push({-dist[y],y});
		    }
    
        }
        return dist;
    }
};

ll howManyRoutes(int curr, digraph &G){
    if(memo[curr] != INDEF) return memo[curr];
    ll res = 0;
    for(pair<int,int> E : G.ady[curr]){
        int u = E.first;
        res = (res + howManyRoutes(u,G)) % MOD;
    }
    return memo[curr] = res;
}

int minFlights(int curr, digraph &G){
    if(memo[curr] != INDEF) return memo[curr];
    int res = 1e9;
    for(pair<int,int> E : G.ady[curr]){
        res = min(res, 1 + minFlights(E.first,G));
    }
    return memo[curr] = res;
}

int maxFlights(int curr, digraph &G){
    if(memo[curr] != INDEF) return memo[curr];
    int res = -1;
    for(pair<int,int> E : G.ady[curr]){
        res = max(res, 1 + maxFlights(E.first,G));
    }
    return memo[curr] = res;
}





int main(){
    FAST_IO
    int n,m;
    cin >> n >> m;
    int a ,b,c; digraph G(n);
    vector<Edge> aristas;
    fore(i,0,m){
        cin >> a >> b >> c; 
        G.addEdge(a-1,b-1,c);
        aristas.push_back(Edge(a-1,b-1,c));
    }
    //Construimos el grafo de caminos minimos
    vector<ll> dist = G.Djikstra(0);
    vector<ll> Indist = G.InDjikstra(n-1);
    ll length = dist[n-1];
    cout << length << " ";

    digraph Gmin(n);
    fore(i,0,m){
        if(dist[aristas[i].v] + aristas[i].c + Indist[aristas[i].w] == length ){
            Gmin.addEdge(aristas[i].v,aristas[i].w,aristas[i].c);
        }
    }
    
    //Cuantas  rutas hay de longitud minima
    //Caso base, 
    memo[n-1] = 1;
    
    cout << howManyRoutes(0,Gmin) << " ";
    
    fore(i,0,n) memo[i] = INDEF; 
    memo[n-1] = 0;
    cout << minFlights(0,Gmin) << " ";
    fore(i,0,n) memo[i] = INDEF; 
    memo[n-1] = 0;
    cout << maxFlights(0,Gmin)<< " ";
    

}



