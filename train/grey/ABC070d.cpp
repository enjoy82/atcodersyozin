#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct edge{
    ll to;
    ll cost;
};

vector<vector<edge> > tree; 
vector<ll> dis;

void solve(ll k, ll d){
    if(dis[k] != -1){
        return;
    }
    dis[k] = d;
    REP(i, 0, tree[k].size()){
        edge next = tree[k][i];
        if(dis[next.to] == -1){
            solve(next.to, d+next.cost);
        }
    }
}

int main(){
    int n; cin >> n;
    tree = vector<vector<edge> >(n);
    dis = vector<ll>(n, -1);
    REP(i, 0, n-1){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        edge e1 = {a, c}, e2 = {b, c};
        tree[b].pb(e1);
        tree[a].pb(e2);
    }
    ll q, k; cin >> q >> k;
    k--;
    solve(k, 0);
    REP(i, 0, q){
        ll a, b; cin >> a >> b;
        a--; b--;
        cout << dis[a] + dis[b] << endl;
    }
}