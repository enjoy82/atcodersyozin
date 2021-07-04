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

#define MAX_V 10000
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

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int main(){
    int n, h, w; cin >> n >> h >> w;
    vector<Pll> pos(n);
    REP(i,0,n){
        ll a, b; cin >> a >> b;
        pos[i] = Pll(a, b);
    }
    REP(i,0,n){
        REP(l,i+1,n){
            ll xd = abs(pos[i].first - pos[l].first);
            chmin(xd, w - xd);
            ll yd = abs(pos[i].second - pos[l].second);
            chmin(yd, h - yd);
            ll d = xd + yd;
            G[i].pb(Pll(d, l));
            G[l].pb(Pll(d, i));
        }
    }
    ll ans = prim();
    cout << ans << endl;
}