#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX 10e17

struct edge{ll to; ll cost;};
vector<vector<edge> > G;
vector<ll> used;

void bfs(ll k){
    queue<edge> q;
    q.push({k, 0});
    while(!q.empty()){
        edge e = q.front();
        ll now = e.to, prec = e.cost;
        q.pop();
        for(int i = 0; i < G[now].size(); i++){
            ll next = G[now][i].to;
            ll c = prec + G[now][i].cost;
            if(used[next] != MAX){continue;}
            used[next] = c;
            q.push({next, c});
        }
    }
}

int main(){
    int n; cin >> n;
    used = vector<ll>(n, MAX);
    G = vector<vector<edge> >(n);
    for(int i = 0; i < n-1; i++){
        ll a, b, c; cin >> a >> b >> c;
        edge e1 = {b-1, c}, e2 = {a-1, c};
        G[a-1].push_back(e1);
        G[b-1].push_back(e2);
    }
    ll q, k; cin >> q >> k;
    bfs(k-1);
    for(int i = 0; i < q; i++){
        ll x, y; cin >> x >> y;
        cout << used[x-1] + used[y-1] << endl;
    }
    return 0;
}