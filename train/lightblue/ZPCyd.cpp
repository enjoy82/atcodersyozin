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

using Graph = vector<vector<int> >; // グラフ

// トポロジカルソートする
void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order) {
    seen[v] = true;
    for (auto next : G[v]) {
        if (seen[next]) continue; // 既に訪問済みなら探索しない
        rec(next, G, seen, order);
    }
    order.push_back(v);
}

int main() {
    int N, M; cin >> N >> M; // 頂点数と枝数
    Graph G(N); // 頂点数 N のグラフ
    for (int i = 0; i < M + N - 1; ++i) {
        int a, b;
        cin >> a >> b; // ノード a からノード b へと有向辺を張る
        a--; b--;
        G[a].push_back(b);
    }

    // 探索
    vector<bool> seen(N, 0); // 初期状態では全ノードが未訪問
    vector<int> order; // トポロジカルソート順
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // 既に訪問済みなら探索しない
        rec(v, G, seen, order);
    }
    reverse(order.begin(), order.end()); // 逆順に

    for (auto v : order) cout << v << " -> ";
    cout << endl;

    vector<int> ans(N);
    int start = order[0];
    ans[start] = 0;
    cout << start << endl;
    // 出力
    vector<int> que;
    que.push(start);
    REP(i, 0, N){
        int now = que.fromt();
        que.pop();
        REP(l, 0, G[now]){
            
        }
    }
}