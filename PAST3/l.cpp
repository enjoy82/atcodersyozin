#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
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
    ll n, m; cin >> n >> m;
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        a--; b--;
        edge e1 = {a, 1};
        edge e2 = {b, 1};
        G[b].pb(e1);
        G[a].pb(e2);
    }
    int s; cin >> s;
    s--;
    int k; cin >> k;
    vector<int> lis(k), flag(n+1, 0);
    REP(i, 0, k){
        cin >> lis[i];
        lis[i]--;
    }
    ll ans = 0;
    REP(i, 0, k){
        int d[MAX_V];
        dijkstra(s, n, d);
        ll idx, mi = 1e9;
        REP(l, 0, k){
            int next = lis[l];
            if(flag[next] == 0){
                if(mi > d[next]){
                    mi = d[next];
                    idx = next;
                }
            }
        }
        flag[idx] = 1;
        ans += mi;
        s = idx;
    }
    cout << ans << endl;
}