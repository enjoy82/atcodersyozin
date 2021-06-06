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

ll rtime(ll now, ll cost, ll dcost){
    auto f = [&](double t) {
        return (double)t + (double)cost + ((double)dcost/(double)(t+1));
    };
    ll st = now;
    double left = now, right = 5e17;
    int cnt = 100;
    while (cnt--) {
        if(abs(right - left) < 0.5) break;
        double c1 = ((double)left * 2 + (double)right) / 3;
        double c2 = ((double)left + (double)right * 2) / 3;

        // もしf(c2)のほうが良い(小さい)なら、駄目な方lowを更新する
        if (f(c1) > f(c2)) left = c1;
        else right = c2;
    }
    auto f2 = [&](ll t) {
        return t + cost + (dcost/(t+1));
    };
    ll k = (ll)right;
    ll kk = max((ll)left, k+1);
    ll kkk = max(st, k-1);
    return min({f2(k), f2(kk), f2(kkk)});
}

///////////////////////////////////////////////////////////////
struct edge{ll to, cost, dcost;};


class Dijkstra{
    public:
        vector<vector<edge>> G;
        vector<ll> d;

        Dijkstra(int n){
            G = vector<vector<edge> >(n);
            d = vector<ll>(n, 2e18);
        }

        void add_edge(ll from, ll to, ll cost, ll dcost){
            edge e = {to, cost, dcost};
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
                for(int i = 0; i < G[v].size(); i++){ //二部探索でどこまで待つか考える
                    edge e = G[v][i];
                    ll cc = rtime(min(d[v], p.first), e.cost, e.dcost);
                    if(d[e.to] > cc){
                        d[e.to] = cc;
                        que.push(Pll(d[e.to], e.to));
                    }
                }
            }
        }
};

int main(){
    int n, m; cin >> n >> m;
    Dijkstra dijk(n);
    REP(i,0,m){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--;
        dijk.add_edge(a,b,c,d);
        dijk.add_edge(b,a,c,d);
    }
    dijk.dijkstra(0);
    if(dijk.d[n-1] == 2e18){
        cout << -1 << endl;
        return 0;
    }
    cout << dijk.d[n-1] << endl;
}