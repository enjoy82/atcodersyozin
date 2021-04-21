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



const long long INF = 1LL << 60;
 
struct edge {
  ll to;
  ll cost;
};

using Graph = vector<vector<edge>>;
 
vector<bool> can_reach(const Graph& G, int start) {
  ll n = G.size();
  vector<bool> ans(n);
  queue<int> que;
 
  que.push(start);
  ans[start] = true;
 
  while (!que.empty()) {
    int index = que.front();
    que.pop();
    for (const auto& it : G[index]) {
      if (ans[it.to] == false) {
        que.push(it.to);
        ans[it.to] = true;
      }
    }
  }
 
  return ans;
}
 
// Bellman Ford
// G: グラフ
// rev: 逆辺のグラフ(負の閉路検出用)
// start: 始点
// goal: 終点
// 戻り値: goalに行くまでの最小コスト。負の閉路が存在する場合は-INFとなる。 負閉路の検知考える！！！！
ll bellman_ford(const Graph& G, const Graph& rev, const int start, const int goal) {
  const int n = G.size();
 
  // 始点からそこまで行くのにかかるのコスト
  vector<ll> cost(n, INF);
  vector<ll> cost_middle;
  cost[start] = 0;
 
  // 閉路がなければn回のループで良いが、閉路検出用にn+1回回す
  for (int i = 0; i < 1e5; i++) {
    // すべての辺を走査
    for (int from = 0; from < n; from++) {
      if (cost[from] == INF) {
        continue;
      }
      for (auto e : G[from]) {
        // 更新
        if (cost[e.to] > cost[from] + e.cost) {
          cost[e.to] = cost[from] + e.cost;
        }
      }
    }
 
    // 閉路検出用
    if (i == n - 1) {
      cost_middle = cost;
    }
  }
 
  // 始点から到達できるか
  auto can_reach_from_start = can_reach(G, start);
  // 終点へ到達できるか
  auto can_reach_from_goal = can_reach(rev, goal);
 
  for (int i = 0; i < n; i++) {
    if (can_reach_from_start[i] && can_reach_from_goal[i]) {
      // 始点から終点へ移動できる経路上のノードの内、値が更新されるものが存在したら負のループが存在する。
      if (cost_middle[i] != cost[i]) {
        return -INF;
      }
    }
  }

  return cost[goal];
}

int main(){
    ll n, m, p; cin >> n >> m >> p;
    vector<vector<edge> > graph(n);
    vector<vector<edge> > rgraph(n);
    REP(i,0,m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        edge e1 = {b, -(c-p)};
        edge e2 = {a, -(c-p)};
        graph[a].pb(e1);
        rgraph[b].pb(e2);
    }
    ll ans = bellman_ford(graph, rgraph, 0, n-1);
    if(ans == -INF){
        cout << -1 << endl;
    }else{
        cout << max(-ans, 0ll) << endl;
    }
}