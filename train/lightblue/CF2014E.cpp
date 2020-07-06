#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define MAX_V 100000
#define INF 100000000

struct edge{int to, cost;};
typedef pair<int, int> P; //first is shortest distance, second is number.

vector<edge> G[MAX_V];

void dijkstra(int s, int V, int d[]){
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
    int s, t; cin >> s >> t;
    s--; t--;
    REP(i, 0, m){
        int x, y, d; cin >> x >> y >> d;
        x--; y--;
        edge e1 = {y, d}, e2 = {x, d};
        G[x].pb(e1);
        G[y].pb(e2);
    }
    REP(i, 0, n){
        int d[MAX_V];
        dijkstra(i, n, d);
        if(d[s] == d[t] && d[s] != INF && d[t] != INF){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}