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

const ll inf =  2 * 1e17;

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示
//vector<map<Pll, ll>> tlis(1e6);
map<Pll, map<ll, ll>> mp;

struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    REP(i, 0, V){
      d[i] = inf;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    REP(i, 0, V){
      d[i] = inf;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      //cout << v << "#v" << d[v] << " " << p.first << endl;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        ll now = d[v];
        //ll k = klis[v][Ple.to];
        for(auto ee : mp[Pll(v, e.to)]){
            ll cost;
            ll tcost = ee.second;
            ll k = ee.first;
            if(d[v] % k == 0){
                cost = tcost;
            }else{
                cost = tcost + (k - (d[v] % k)); 
            }
            //cout << "OK" << cost <<d[v] <<   " "<< v << e.to << endl;
            //cout << tcost << " " << k << endl;
            if(d[e.to]>d[v]+cost){
                d[e.to] = d[v]+cost;
                que.push(P(d[e.to],e.to));
            }
        }
      }
    }
  }
};

int main(){
    ll n, m, x, y; cin >> n >> m >> x >> y;
    x--; y--;
    graph g(n);
    REP(i, 0, m){
        ll a, b, t, k; cin >> a >> b >> t >> k;
        a--; b--;
        g.add_edge(a, b, t);
        g.add_edge(b, a, t);
        if(mp[Pll(a, b)].count(k)){
            mp[Pll(a, b)][k] = min(t, mp[Pll(a, b)][k]);
        }else{
            mp[Pll(a, b)][k] = t;
        }
        if(mp[Pll(b, a)].count(k)){
            mp[Pll(b, a)][k] = min(t, mp[Pll(b, a)][k]);
        }else{
            mp[Pll(b, a)][k] = t;
        }
    }
    g.dijkstra(x);
    if(g.d[y] == inf){
        cout << -1 << endl;
        return 0;
    }else{
        cout << g.d[y] << endl;
    }
}