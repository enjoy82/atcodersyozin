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

#define MAX_V 500000
#define INF 100000000

//クラスカル使え！！！

vector<Pll> G[MAX_V]; // (cst, to)
bool used[MAX_V]; 
vector<ll> sp;

ll prim() {
    priority_queue<Pll, vector<Pll>, greater<Pll> > que;
    memset(used, 0ll, sizeof(used));
    que.push(Pll(0,0));
    ll ret = 0;
    while(!que.empty()) {
        ll cst = que.top().first, v = que.top().second;
        que.pop();
        if(used[v]) continue;
        used[v] = 1;
        ret += cst;
        sp.pb(cst);
        for(int i = 0; i < G[v].size(); i++)
            que.push(Pll(G[v][i].first, G[v][i].second));
    }
    return ret;
}

int main(){
    int n, m, k; cin >> n >> m >> k;
    REP(i,0,m){
        ll a, b, c; cin >> a >> b >> c;
        G[a].pb(Pll(c,b));
        G[b].pb(Pll(c,a));
    }
    G[0].pb(Pll(0,1));
    ll ans = prim();
    sort(ALL(sp), greater<>());
    REP(i,0,k-1){
        ans -= sp[i];
    }
    cout << ans << endl;
}