#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define MAX_V 1000000
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
vector<edge> rG[MAX_V];


int main(){
    int n, m; cin >> n >> m;
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        a--; b--;
        G[b].pb({a, 1});
        rG[a].pb({b, 1});
    }
    int k; cin >> k;
    vector<int> klis(k);
    REP(i, 0, k){
        int a; cin >> a;
        a--;
        klis[i] = a;
    }
    int mi = 0, ma = 0;
    dijkstra(klis.back(), n);
    REP(i, 0, k-1){
        int f = 0, f1 = 0;
        if(d[klis[i]] != d[klis[i+1]]+1){
            mi++;
            ma++;
        }else{
            int c = d[klis[i+1]], count = 0;
            REP(l, 0, rG[klis[i]].size()){
                int next = rG[klis[i]][l].to;
                if(d[next] == c){
                    count++;
                }
            }
            if(count >= 2){
                ma++;
            }
        }
    }
    cout << mi << " " << ma << endl;
}