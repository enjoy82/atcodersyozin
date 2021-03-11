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

#define MAX_V 300000
#define INF 1e16

struct edge{ll to, cost;};
typedef pair<ll, ll> P; //first is shortest distance, second is number.

vector<edge> rG[MAX_V];
ll rd[MAX_V];

void rdijkstra(int s, int V){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(rd, rd+V, INF);
    rd[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        ll v = p.second;
        if(rd[v] < p.first) continue;
        for(int i = 0; i < rG[v].size(); i++){
            edge e = rG[v][i];
            if(rd[e.to] > rd[v] + e.cost){
                rd[e.to] = rd[v] + e.cost;
                que.push(P(rd[e.to], e.to));
            }
        }
    }
}

vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(int s, int V){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top(); que.pop();
        ll v = p.second;
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

template <class T>
class SegTree {
    int n;                       // 葉の数
    vector<T> data;              // データを格納するvector
    T def;                       // 初期値かつ単位元
    function<T(T, T)> operation; // 区間クエリで使う処理
    function<T(T, T)> update;    // 点更新で使う処理
 
    // 区間[a,b)の総和。ノードk=[l,r)に着目している。
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def; // 交差しない
        if (a <= l && r <= b)
            return data[k]; // a,l,r,bの順で完全に含まれる
        else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
            return operation(c1, c2);
        }
    }
 
  public:
    // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,
    // _update:更新関数
    SegTree(size_t _n, T _def, function<T(T, T)> _operation,
            function<T(T, T)> _update)
        : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
    }
 
    // 場所i(0-indexed)の値をxで更新
    void change(int i, T x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
 
    // [a, b)の区間クエリを実行
    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }
 
    // 添字でアクセス
    T operator[](int i) {
        return data[i + n - 1];
    }
};


//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int main(){
    int n, m, s, t; cin >> n >> m >> s >> t;
    s--; t--;
    REP(i, 0, m){
        ll u, v, a, b; cin >> u >> v >> a >> b;
        u--; v--;
        rG[u].pb({v, b});
        rG[v].pb({u, b});
        G[u].pb({v, a});
        G[v].pb({u, a});
    }
    SegTree<long long> st(n, INF,
                          [](long long a, long long b) { return min(a, b); }, //ラムダ式でオペレーター渡してる
                          [](long long a, long long b) { return b; });
    //初期値の配列がほしかったら一個ずつ添え字のせてupdateする
    dijkstra(s, n);
    rdijkstra(t, n);
    vector<ll> lis(n, 0);
    REP(i, 0, n){
        lis[i] = rd[i] + d[i];
        st.change(i, lis[i]);
    }
    REP(i, 0, n){
        cout << 1000000000000000 - st.query(i, n+1) << endl;
    }
} 