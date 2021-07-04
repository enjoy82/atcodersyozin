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

struct edge{ll to, cost;};

class Dijkstra{
    public:
        vector<vector<edge>> G;
        vector<ll> d;
        vector<int> charlis;
        ll sn;

        Dijkstra(int n){
            G = vector<vector<edge> >(n);
            d = vector<ll>(n, 1e18);
            charlis = vector<int>(n, -1);
            sn = n;
        }

        void add_edge(ll from, ll to, ll cost){
            edge e = {to, cost};
            edge e1 = {from, cost};
            G[from].pb(e);
            G[to].pb(e1);
        }

        void dijkstra(ll s, ll from){
            d = vector<ll>(sn, 1e18);
            charlis = vector<int>(sn, -1);
            priority_queue<pair<ll, tuple<int, int, int>>, vector<pair<ll, tuple<int, int, int>>>, greater<pair<ll, tuple<int, int, int>>> > que;
            d[s] = 0;
            que.push(pair<ll, tuple<int, int, int>>(0, make_tuple(s, from, -1)));
            
            while(!que.empty()){
                pair<ll, tuple<int, int, int>> p = que.top(); que.pop();
                ll v = get<0>(p.second);
                if(d[v] < p.first) continue;
                for(int i = 0; i < G[v].size(); i++){
                    edge e = G[v][i];
                    if(d[e.to] > d[v] + e.cost && e.to != get<1>(p.second)){
                        if(chmin(d[e.to], d[v] + e.cost)){
                            if(get<2>(p.second) == -1){
                                charlis[e.to] = e.to;
                            }else{
                                charlis[e.to] = get<2>(p.second);
                            }
                        }
                        if(get<2>(p.second) == -1){
                            que.push(pair<ll, tuple<int, int, int>>(d[e.to], make_tuple(e.to, v, e.to)));
                        }else{
                            que.push(pair<ll, tuple<int, int, int>>(d[e.to], make_tuple(e.to, v, get<2>(p.second))));
                        }
                    }
                }
            }
            
        }
};

int main(){
    ll n, m; cin >> n >> m;
    int s, t; cin >> s >> t;
    s--; t--;
    Dijkstra dijk(n);
    REP(i,0,m){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dijk.add_edge(a,b,c);
    }
    vector<vector<ll> > dlis(n, vector<ll>(n, 0));
    REP(from,0,n){
        REP(ss,0,n){
            //if(from == ss) continue;
            dijk.dijkstra(ss, from);
            //経路復元する
            dlis[from][ss] = dijk.charlis[t];
            
            cout << "# " << from << " " << ss << endl;
            REP(i,0,n){
                cout << dijk.d[i] << " ";
            }
            cout << endl;
            
        }
    }
    int p; cin >> p;
    vector<ll> plis(p);
    REP(i,0,p){
        cin >> plis[i];
        plis[i]--;
    }
    REP(i,1,p-1){
        cout << dlis[s][plis[i]]+1 << endl;
        s = plis[i];
    }
}