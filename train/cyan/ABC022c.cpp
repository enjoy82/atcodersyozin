#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define MAX_V 300
#define INF 100000000

struct edge{int to, cost;};
typedef pair<int, int> P; //first is shortest distance, second is number.

vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s, int V){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    REP(i, 0, m){
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        G[a].pb({b, l});
        G[b].pb({a, l});
    }
    int ans = 1e9;
    int k = G[0].size();
    REP(i, 0, k){
        int t = G[0][0].to;
        int c = G[0][0].cost;
        int l = 0;
        for(; l < G[t].size(); l++){
            if(G[t][l].to == 0){
                break;
            }
        }
        G[0].erase(G[0].begin());
        G[t].erase(G[t].begin()+l);
        dijkstra(t, n);
        G[0].pb({t, c});
        G[t].pb({0, c});
        ans = min(ans, c + d[0]);
        REP(i, 0, MAX_V){
            d[i] = INF;
        }
    }
    if(ans >= INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}