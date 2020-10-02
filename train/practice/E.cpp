// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll big = 1e12;

int main(){
    int n, k; cin >> n >> k;
    mcf_graph<int , ll> g(2*n + 2);
    int s = 2 * n, t = 2 * n + 1;
    REP(i, 0, n){
        g.add_edge(s, i, k, 0);
        g.add_edge(n+i, t, k, 0);
    }

    REP(i, 0, n){
        REP(l, 0, n){
            ll a; cin >> a;
            g.add_edge(i, n+l, 1, big - a);
        }
    }
    g.add_edge(s, t, n * k, big);
    auto result = g.flow(s, t, n * k);
    cout << 1LL * n * k * big - result.second << endl;

    vector<string> grid(n, string(n, '.'));
    for(auto e : g.edges()){
        if(e.from == s || e.to == t || e.flow == 0) continue;
        grid[e.from][e.to - n] = 'X';
    }
    REP(i, 0, n){
        cout << grid[i] << endl;
    }
}