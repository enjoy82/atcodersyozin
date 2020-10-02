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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

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
    return q.first;
}


void solve(){
    ll n, a, b, da, db; cin >> n >> a >> b >> da >> db;
    a--; b--;
    Graph G(n);
    REP(i, 0, n-1){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(Pll(v, 1ll));
        G[v].push_back(Pll(u, 1ll));
    }
    ll ret = tree_diamiter(G);
    vector<int> flag(n, -1);
    flag[a] = 0;
    stack<int> st;
    st.push(a);
    while(!st.empty()){
        int now = st.top();
        st.pop();
        REP(i, 0, G[now].size()){
            int next = G[now][i].first;
            if(flag[next] == -1){
                flag[next] = flag[now] + 1;
                st.push(next);
            }
        }
    }
    if(flag[b] <= da){
        cout << "Alice" << endl;
        return;
    }
    cout << ret << endl;
    if(min(ret, db) >= 2 *da){
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl;
    return;
}   

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}