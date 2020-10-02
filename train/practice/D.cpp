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

int main(){
    int n, m; cin >> n >> m;
    vector<string> lis(n);
    mf_graph<int> g(n * m + 2);
    int s = n * m, t = n * m + 1;
    REP(i, 0, n){
        cin >> lis[i];
    }
    REP(i, 0, n){
        REP(l, 0, m){
            if(lis[i][l] == '.'){
                int v = i * m + l;
                if((i + l) % 2 == 0){
                    g.add_edge(s, v, 1);
                }else{
                    g.add_edge(v, t, 1);
                }
            }
        }
    }

    REP(i, 0, n){
        REP(l, 0, m){
            if((i + l) % 2  == 0 && lis[i][l] == '.'){
                int v = i * m + l;
                REP(k, 0, 4){
                    int x = i + dx[k], y = l + dy[k];
                    if(x >= 0 && x < n && y >= 0 && y < m && lis[x][y] == '.'){
                        g.add_edge(v, x * m + y, 1);
                    }
                }
            }
        }
    }

    cout << g.flow(s, t) << endl;

    auto edges = g.edges();
    for(auto e : edges){
        if(e.from == s || e.to == t || e.flow == 0) continue;
        int i0 = e.from / m, l0 = e.from % m;
        int i1 = e.to / m, l1 = e.to % m;
        if (i0 == i1 + 1) {
            lis[i1][l1] = 'v';
            lis[i0][l0] = '^';
        } else if (l0 == l1 + 1) {
            lis[i1][l1] = '>';
            lis[i0][l0] = '<';
        } else if (i0 == i1 - 1) {
            lis[i0][l0] = 'v';
            lis[i1][l1] = '^';
        } else {
            lis[i0][l0] = '>';
            lis[i1][l1] = '<';
        }
    }

    REP(i, 0, n){
        cout << lis[i] << endl;
    }
}