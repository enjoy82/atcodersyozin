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

vector<vector<int> > route;
map<ll, ll> bitmap;

void dfs(Graph &G, int now, int goal, int n, int count, ll state, vector<int> r){
    if(now == goal)
        route.pb(r);
    if(count == n)
        return;
    REP(i,0,G[now].size()){
        int next = G[now][i].to;
        if((1ll<<next) & state)
            continue;
        ll nstate = state | (1<<next);
        vector<int> r1 = r;
        r1.pb(next);
        dfs(G, next, goal, n, count+1, nstate, r1);
    }
}

int main(){
    int n, m, p, a, b; cin >> n >> m >> p >> a >> b;
    a--; b--;
    vector<double> tichet(n);
    REP(i,0,n){cin >> tichet[i];}
    Graph G(m);
    REP(i,0,p){
        ll x, y, z; cin >> x >> y >> z;
        x--; y--;
        Edge e1 = {y, z};
        Edge e2 = {x, z};
        G[x].pb(e1);
        G[y].pb(e2);
    }
    vector<int> r;
    r.pb(0);
    ll state = (1<<a);
    dfs(G, a, b, n, 0, state, r);
    REP(i,0,route.size()){
        REP(l,0,route[i].size()){
            cout << route[i][l] << " ";
        }
        cout << endl;
    }
    if(route.size() == 0){
        cout << "Impossible" << endl;
        continue;
    }
    
}