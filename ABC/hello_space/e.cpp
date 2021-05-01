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

struct edge{int to, cost;};

class Dijkstra{
    public:
        vector<vector<edge>> G;
        vector<int> d;

        Dijkstra(int n){
            G = vector<vector<edge> >(n);
            d = vector<int>(n, 2e9);
        }

        void add_edge(int from, int to, int cost){
            edge e = {to, cost};
            G[from].pb(e);
        }

        void dijkstra(int s){
            priority_queue<Pii, vector<Pii>, greater<Pll> > que;
            d[s] = 0;
            que.push(Pii(0, s));

            while(!que.empty()){
                Pii p = que.top(); que.pop();
                int v = p.second;
                if(d[v] < p.first) continue;
                for(int i = 0; i < G[v].size(); i++){
                    edge e = G[v][i];
                    if(d[e.to] > d[v] + e.cost){
                        d[e.to] = d[v] + e.cost;
                        que.push(Pii(d[e.to], e.to));
                    }
                }
            }
        }
};

int main(){
    int r, c; cin >> r >> c;
    vector<vector<int> > alis(r, vector<int>(c-1)), blis(r-1, vector<int>(c));
    REP(i,0,r){
        REP(l,0,c-1){
            cin >> alis[i][l];
        }
    }
    REP(i,0,r-1){
        REP(l,0,c){
            cin >> blis[i][l];
        }
    }
    Dijkstra dijk(r * c);
    REP(i,0,r){
        REP(l,0,c){
            int pos = i + l * r;
            int npos;
            if(l < c - 1){
                npos = i + (l + 1) * r;
                dijk.add_edge(pos, npos, alis[i][l]);
            }
            
            if(l-1 >= 0){
                npos = i + (l-1) * r;
                dijk.add_edge(pos, npos, alis[i][l-1]);
            }
            
            if(i < r-1){
                npos= (i+1) + l * r;
                dijk.add_edge(pos, npos, blis[i][l]);
            }

            REP(k,1 ,r){
                if(i-k >= 0){
                    npos = (i-k) + l * r;
                    dijk.add_edge(pos, npos, 1 + k);
                }else{
                    break;
                }
            }
        }
    }
    dijk.dijkstra(0);
    cout << dijk.d[r * c - 1] << endl;
}