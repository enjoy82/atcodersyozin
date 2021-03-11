// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//ordered_set 重複不可
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

#define MAX_V 10000
#define INF 200000000000

struct edge{ll to, cost;};
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
    int n, m; cin >> n >> m;
    map<int, ll> mp;
    REP(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        if(a == b){
            if(!mp.count(a))
                mp[a] = 1e12;
            mp[a] = min(mp[a], c);
        }
        edge e = {b, c};
        G[a].pb(e);
    }
    vector<vector<ll> > d_lis(n, vector<ll>(n));
    REP(i, 0, n){
        dijkstra(i, n);
        REP(l, 0, n){
            d_lis[i][l] = d[l];
            //cout << d[l] << " ";
        }
        //cout << endl;
    }
    REP(i, 0, n){
        ll ma = 200000000000;
        int f = 0;
        if(mp.count(i)){
            ma = mp[i];
            f = 1;
        }
        REP(l, 0, n){
            if(i == l)
                continue;
            ll mid = d_lis[i][l] + d_lis[l][i];
            if(chmin(ma, mid)){
                f = 1;
            }
        }
        if(f == 1){
            cout << ma << endl;
        }else{
            cout << -1 << endl;
        }
    }
}