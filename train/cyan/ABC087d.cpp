#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


const ll INF = 2e9;

struct edge{
    ll to; ll cost;
};

int main(){
    int n, m; cin >> n >> m;
    vector<vector<edge> > tree(n);
    vector<ll> dist(n, INF);
    REP(i, 0, m){
        ll l, r, d; cin >> l >> r >> d;
        l--, r--;
        tree[l].pb({r, d});
        tree[r].pb({l, -1*d});
    }
    REP(i, 0, n){
        if(dist[i] != INF){continue;}
        dist[i] = 0;
        stack<ll> s;
        s.push(i);
        while(!s.empty()){
            int now = s.top();
            s.pop();
            REP(l, 0, tree[now].size()){
                edge e = tree[now][l];
                int next = e.to, c = e.cost;
                if(dist[next] == INF){
                    dist[next] = dist[now] + c;
                    s.push(next);
                }else{
                    if(dist[next] == dist[now] + c){
                        continue;
                    }else{
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}