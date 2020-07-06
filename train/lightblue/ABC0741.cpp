#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

#define MAX_V 100000
#define INF 1e15

struct edge{ll to, cost;};
typedef pair<ll, ll> P; //first is shortest distance, second is number.

vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s, ll V){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0LL;
    que.push(P(0LL, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;
        for(ll i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

vector<edge> G1[MAX_V];
ll d1[MAX_V];

void dijkstra1(ll s, ll V){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d1, d1+V, INF);
    d1[s] = 0LL;
    que.push(P(0LL, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        ll v = p.second;
        if(d1[v] < p.first) continue;
        for(ll i = 0; i < G1[v].size(); i++){
            edge e = G1[v][i];
            if(d1[e.to] > d1[v] + e.cost){
                d1[e.to] = d1[v] + e.cost;
                que.push(P(d1[e.to], e.to));
            }
        }
    }
}

int dd[400][400];
int V; //頂点数

void warshall_floyd(){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int l = 0; l < V; l++){
                dd[i][l] = min(dd[i][l], dd[i][k] + dd[k][l]);
            }
        }
    }
}

int main(){
    int n; cin >> n;
    V = n;
    vector<vector<ll> > lis(n, vector<ll>(n));
    vector<vector<ll> > edgelis(0, vector<ll>(3, 0));
    REP(i, 0, n){
        REP(l, 0, n){
            ll a; cin >> a;
            lis[i][l] = a;
            dd[i][l] = a;
            if(a == 0){
                continue;
            }
            edge e = {l, a};
            edge e1 = {i, a};
            G[i].pb(e);
            G[l].pb(e1);
            edgelis.pb({a, i, l});
        }
    }
    REP(i, 0, n){
        dijkstra(i, n);
        REP(l, 0, n){
            if(lis[i][l] != d[l]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    sort(ALL(edgelis), [](auto &x, auto &y){return x[0] < y[0];});
    vector<int> flag(n, 0);
    ll ans = 0;
    warshall_floyd();
    REP(i, 0, edgelis.size()){
        ll c = edgelis[i][0], from = edgelis[i][1], to = edgelis[i][2];
        ll f = 1;
        if(dd[from][to] == c){
            REP(l, 0, n){
                if(l == from || l == to){
                    continue;
                }
                if(dd[from][l] + dd[l][to] <= c){
                    f = 0;
                    break;
                }
            }
            ans += c * f;
        }
    }
    cout << ans/2 << endl;
}
