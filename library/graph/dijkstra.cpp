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

class Dijkstra{
    public:
        Graph G;
        vector<ll> d;

        Dijkstra(int n){
            G = Graph(n);
            d = vector<ll>(n, 1e18);
        }

        void add_edge(ll from, ll to, ll cost){
            Edge e = {to, cost};
            G[from].pb(e);
        }

        void dijkstra(ll s){
            priority_queue<Pll, vector<Pll>, greater<Pll> > que;
            d[s] = 0;
            que.push(Pll(0, s));

            while(!que.empty()){
                Pll p = que.top(); que.pop();
                ll v = p.second;
                if(d[v] < p.first) continue;
                for(int i = 0; i < G[v].size(); i++){
                    Edge e = G[v][i];
                    if(d[e.to] > d[v] + e.cost){
                        d[e.to] = d[v] + e.cost;
                        que.push(Pll(d[e.to], e.to));
                    }
                }
            }
        }
};
///////////////////////////////////////////////////////////////


int main(){
    int n, m, s, t; cin >> n >> m >> s >> t;
    s--; t--;
    Dijkstra dijk(n);
    Dijkstra rdijk(n);
    REP(i, 0, m){
        ll u, v, a, b; cin >> u >> v >> a >> b;
        u--; v--;
        rdijk.add_edge(u, v, b);
        rdijk.add_edge(v, u, b);
        dijk.add_edge(u, v, a);
        dijk.add_edge(v, u, a);
    }

    rdijk.dijkstra(t);
    dijk.dijkstra(s);
    vector<ll> lis(n, 0);
    REP(i, 0, n){
        lis[i] = rdijk.d[i] + dijk.d[i];
    }
    REP(i, 0, n){
        cout << lis[i] << " " << endl;
    }
} 