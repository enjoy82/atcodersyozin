// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

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

template <typename T>
struct Edge{
    int to;
    T cost;
};
using Graph = vector<vector<Pll>>;

//木の直径
Pll dfs(Graph &G, int u, int par) {  // 最遠点間距離と最遠点を求める
    Pll ret = make_pair(0ll, u);
    for (auto e : G[u]) {
        if (e.first == par) continue;
        auto next = dfs(G, e.first, u);
        next.first += e.second;
        ret = max(ret, next);
    }
    return ret;
}
ll tree_diamiter(Graph &G) {
    Pll p = dfs(G, 0, -1);
    Pll q = dfs(G, p.second, -1);
    cout << p.second + 1 << " " <<  q.second + 1<< endl; 
    return q.first;
}

int main(){
    int n; cin >> n;
    Graph G(n);
    REP(i, 0, n-1){
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(Pll(b, 1ll));
        G[b].push_back(Pll(a, 1ll));
    }
    ll ret = tree_diamiter(G);
    //out << ret << endl;
}