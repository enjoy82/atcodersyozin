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

template <class T>
inline vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts>
inline auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示
struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

const long long LINF = 1LL << 60;
const long long INF = 1LL << 30;

int V, E; //頂点数 辺の数
vector<vector<int>> G(V); //頂点の隣接リスト
vector<int> ord_pre(V, INF); //行きがけ順の記録
vector<int> lowlink(V, INF); //lowlinkの記録
vector<pair<int, int>> Bridges; //橋のリスト
vector<int> ArticulationPoints; //関節点のリスト

int pre = 0; //行きがけ順序

void recdfs(int p, int u){ //p : uの親
  ord_pre[u] = pre++; //uの番号を確定する
  lowlink[u] = ord_pre[u];

  int cnt = 0; //DFS木次数カウント
  bool isArt = false; //関節点か否か

  for(int v: G[u]){ //uから行ける頂点vについて
    if(ord_pre[v]==INF){ //未訪問ならばuの子なので
      cnt++;

      recdfs(u, v); //uの子であるvの番号を確定させる //vのlowlinkも確定
      lowlink[u] = min(lowlink[u], lowlink[v]);

      if(ord_pre[u] < lowlink[v])Bridges.push_back({u,v}); //橋の判定してリストに入れる
      if(p!=-1 && ord_pre[u]<=lowlink[v])isArt = true; //根以外の関節点判定

    }else if( v != p ){
      //このとき uv が後退辺
      lowlink[u] = min(lowlink[u], ord_pre[v]);
    }
  }
  if(p==-1 && cnt>1)isArt = true; //根の関節点判定
  if(isArt)ArticulationPoints.push_back(u); //関節点だったらリストに入れる
}

int main(){
  cin>>V>>E;
  G.resize(V);
  for(int i=0; i<E; i++){
    int s,t;
    cin>>s>>t;
    G[s].push_back(t);
    G[t].push_back(s);
  }

  ord_pre.assign(V, INF);
  lowlink.assign(V,INF);
  pre = 0;
  recdfs(-1, 0);

  //* 3a
  sort(ALL(ArticulationPoints));
  for(int x: ArticulationPoints)cout<<x<<endl;
  //*/

  /* 3b
  for(auto &x: Bridges){
    if(x.first>x.second)swap(x.first, x.second);
  }
  sort(ALL(Bridges));
  for(auto x: Bridges)cout<<x.first<<" "<<x.second<<endl;
  */
}