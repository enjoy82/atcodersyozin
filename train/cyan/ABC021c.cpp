#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll mod = 1e9+7;

#define MAX_V 200
#define INF 150000000

struct edge{int to, cost;};
typedef pair<int, int> P; //first is shortest distance, second is number.

vector<edge> G[MAX_V];
ll d[MAX_V];

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
    int n; cin >> n;
    int a, b; cin >> a >> b;
    a--; b--;
    int m; cin >> m;
    REP(i, 0, m){
        int x, y; cin >> x >> y;
        x--; y--;
        G[x].pb({y, 1});
        G[y].pb({x, 1});
    }
    dijkstra(a, n);
    vector<vector<ll> > tpo(n, vector<ll>(2, 0));
    REP(i, 0, n){
        tpo[i][0] = d[i];
        tpo[i][1] = i;
    }
    vector<ll> anslis(n, 0);
    anslis[a] = 1;
    sort(ALL(tpo), [](auto &x, auto &y){return x[0] < y[0];});
    REP(i, 0, n){
        int now = tpo[i][1];
        REP(l, 0, G[now].size()){
            int next = G[now][l].to;
            if(d[next] > d[now])
                anslis[next] = (anslis[next] + anslis[now])%mod;
        }
    }
    cout << anslis[b] << endl;
    return 0;
}