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

//https://algo-logic.info/warshall-floyd/
/* is_negative(dist)
    入力：warshall_floyd で得た dist
    出力：負の有向路を含むかどうか
*/
bool is_negative(const vector<vector<long long>> &dist) {
    int V = dist.size();
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            return true;
        }
    }
    return false;
}

void warshall_floyd(vector<vector<ll> > &Graph, int V){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int l = 0; l < V; l++){
                Graph[i][l] = min(Graph[i][l], Graph[i][k] + Graph[k][l]);
            }
        }
    }
}

int main(){
    int v, e; cin >> v >> e;
    auto G = make_vec(v, v, LINF);
    REP(i,0,v)
        G[i][i] = 0;
    REP(i,0,e){
        ll s, t, v; cin >> s >> t >> v;
        G[s][t] = v;
    }
    warshall_floyd(G, v);
    if(is_negative(G)){
        cout << "NEGATIVE CYCLE" << endl;;
        return 0;
    }
    REP(i,0,v){
        REP(l,0,v){
            if(G[i][l] < (LINF >> 2))
                cout << G[i][l];
            else
                cout << "INF";

            if (l == v - 1)cout << endl;
			else cout << " ";
        }
    }
    return 0;
}