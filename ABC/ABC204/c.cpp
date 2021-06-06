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

///////////////////////////////////////////////////////////////
struct edge{ll to, cost;};

class Dijkstra{
    public:
        vector<vector<edge>> G;
        vector<ll> d;

        Dijkstra(int n){
            G = vector<vector<edge> >(n);
            d = vector<ll>(n, 1e18);
        }

        void add_edge(ll from, ll to, ll cost){
            edge e = {to, cost};
            G[from].pb(e);
        }

        void dijkstra(ll s){
            d = vector<ll>(d.size(), 1e18);
            priority_queue<Pll, vector<Pll>, greater<Pll> > que;
            d[s] = 0;
            que.push(Pll(0, s));

            while(!que.empty()){
                Pll p = que.top(); que.pop();
                ll v = p.second;
                if(d[v] < p.first) continue;
                for(int i = 0; i < G[v].size(); i++){
                    edge e = G[v][i];
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
    int n; cin >> n;
    Dijkstra dijk(n);
    int m; cin >> m;
    REP(i,0,m){
        int a, b; cin >> a >> b;
        a--; b--;
        dijk.add_edge(a, b, 1);
    }
    int ans = 0;
    REP(i,0,n){
        dijk.dijkstra(i);
        REP(l,0,dijk.d.size()){
            if(dijk.d[l] != 1e18){
                ans++;
            }
        }
    }
    cout << ans << endl;
}