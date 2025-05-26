#include <bits/stdc++.h>
#define fore(i, a, b) for (int i = a; i < (int)b; i++)
#define dfore(i, a, b) for (int i = a; i >= (int)b; i--)
#define FAST_IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

const int INDEF = -1;
const ll INF = 1e18;
const int MINF = -1e9;

struct edge
{
    int tg;
    int cost;

    edge()
    {
        tg = 0;
        cost = 0;
    }
    edge(int end, int costo)
    {
        cost = costo;
        tg = end;
    }
};

struct digraph
{
    vector<vector<edge>> ady;
    vector<vector<edge>> inAdy;
    digraph(int V) { ady.resize(V), inAdy.resize(V); }

    void addEdge(int v, int w, int c)
    {
        ady[v].push_back(edge(w, c));
        inAdy[w].push_back(edge(v, c));
    }

    vector<ll> invRoutes(int og)
    {
        vector<ll> d(ady.size(), INF);
        d[og] = 0;
        priority_queue<pair<ll, int>> pq;
        pq.push({0,og});
        while (!pq.empty())
        {
            int curr, curDist;
            tie(curDist, curr) = pq.top(); pq.pop();
            curDist = -curDist;
            
            for(edge ar : inAdy[curr]){
                if(ar.cost + curDist < d[ar.tg]){
                    d[ar.tg] = ar.cost + curDist;
                    pq.push({-d[ar.tg],ar.tg});
                }
            }
        }
        return d;
    }

    multiset<int> Routes(int og, vector<ll> &invDist){
         vector<ll> d(ady.size(), INF);
        d[og] = 0;
        priority_queue<pair<ll, int>> pq;
        pq.push({0,og});
        multiset<int> res;
        while(!pq.empty()){
            int curr; ll curDist;
            tie(curDist, curr) = pq.top(); pq.pop();
            curDist = -curDist;

            

            for(edge ar : ady[curr]){
                if(ar.cost + curDist < d[ar.tg]){
                    res.insert(ar.cost + curDist + invDist[ar.tg]);
                    d[ar.tg] = ar.cost + curDist;
                    pq.push({-d[ar.tg],ar.tg});
                }
            }
        }
        return res;
    }
};

int main()
{
    FAST_IO
    int n, m, k;
    cin >> n >> m >> k;
    digraph G(n);

    fore(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G.addEdge(a-1,b-1,c);
    }

    vector<ll> invD = G.invRoutes(n-1);
    multiset<int> res = G.Routes(0,invD);
    auto it = res.begin();
    fore(i,0,k){
        cout << *it << " ";
        it++;
    }
}
