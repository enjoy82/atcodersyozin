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

ll n, m, l;

#define MAX_V 1000

ll d[MAX_V][MAX_V];
int V; //頂点数

ll d2[MAX_V][MAX_V];

void warshall_floyd(){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void warshall_floyd2(){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
            }
        }
    }
}

int main(){
    cin >> n >> m >> l;
    V = n;
    REP(i,0,MAX_V){
        REP(k,0,MAX_V){
            if(i == k){
                d[i][k] = 0;
                continue;
            }
            d[i][k] = 1e18;
        }
    }
    REP(i,0,m){
        ll a, b, c; cin >> a >> b >> c;
        if(c > l){
            continue;
        }
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    warshall_floyd();
    REP(i,0,MAX_V){
        REP(j,0,MAX_V){
            d2[i][j] = 1e18;
        }
    }
    REP(i,0,n){
        REP(k,0,n){
            //cout << i << k << endl;
            if(i == k){
                d2[i][k] = 0;
                continue;
            }
            //cout << i << k << endl;
            if(d[i][k] <= l){
                d2[i][k] = 1;
                d2[i][k] = 1;
            }
        }
    }
    warshall_floyd2();
    int q; cin >> q;
    REP(i,0,q){
        int s, t; cin >> s >>  t;
        s--; t--;
        if(s > t){
            int z = t;
            t = s;
            s = z;
        }
        if(d2[s][t] >= 1e18){
            cout << -1 << endl;
        }else{
            //cout << d2[s][t] << endl;
            cout << max(d2[s][t] - 1, 0ll) << endl;
        }
    }
}