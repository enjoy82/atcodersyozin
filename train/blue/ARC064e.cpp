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
using Pld = pair<ld, ll>;
struct edge{ll to; ld cost;};

class Dijkstra{
    public:
        vector<vector<edge>> G;
        vector<ld> d;

        Dijkstra(int n){
            G = vector<vector<edge> >(n);
            d = vector<ld>(n, 1e18);
        }

        void add_edge(ll from, ll to, ld cost){
            edge e = {to, cost};
            G[from].pb(e);
        }

        void dijkstra(ll s){
            priority_queue<Pld, vector<Pld>, greater<Pld> > que;
            d[s] = 0.0;
            que.push(Pld(0.0, s));

            while(!que.empty()){
                Pld p = que.top(); que.pop();
                ll v = p.second;
                if(d[v] < p.first) continue;
                for(int i = 0; i < G[v].size(); i++){
                    edge e = G[v][i];
                    if(d[e.to] > d[v] + e.cost){
                        d[e.to] = d[v] + e.cost;
                        que.push(Pld(d[e.to], e.to));
                    }
                }
            }
        }
};
///////////////////////////////////////////////////////////////



ld distance(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2){
    ld xdis = abs(x1 - x2)*1.0, ydis = abs(y1 - y2)*1.0;
    ld dis = pow((xdis * xdis + ydis * ydis), 0.5);
    if(dis - r1 - r2 >= 0){
        return dis - r1 - r2;
    }else{
        return 0;
    }
}

int main(){
    ll xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    int n; cin >> n;
    vector<vector<ll> > lis(n+2, vector<ll>(3));
    lis[0][0] = xs;
    lis[0][1] = ys;
    lis[0][2] = 0;
    lis[n+1][0] = xt;
    lis[n+1][1] = yt;
    lis[n+1][2] = 0;
    Dijkstra G(n+2);
    REP(i, 0, n){
        cin >> lis[i+1][0] >> lis[i+1][1] >> lis[i+1][2];
    }
    REP(i,0, n+2){
        REP(l, i+1, n+2){
            ld dis = distance(lis[i][0], lis[i][1], lis[i][2], lis[l][0], lis[l][1], lis[l][2]);
            G.add_edge(i, l, dis);
            G.add_edge(l, i, dis);
        }
    }
    G.dijkstra(0);
    cout << std::fixed << std::setprecision(15) << G.d[n+1] << endl;
}