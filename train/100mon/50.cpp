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

int n, m;
vector<vector<pair<ll, Pll>> > lis;

int main(){
    cin >> n >> m;
    REP(i,0,m){
        ll s, t, d, ti; cin >> s >> t >> d >> ti;
        s--; t--;
        pair<ll, Pll> e = {t, Pll(d, ti)};
        pair<ll, Pll> e1 = {s, Pll(d, ti)};
        lis[s].pb(e);
        lis[t].pb(e1);
    }
    queue<Pll> que;
    que.push(0ll, -1);
    vector<Pll> bitdp((1<<n), vector<ll>(n, 1e18));
    while(!que.empty()){
        Pll now = que.front();
        ll pos = now.second;
        ll s = now.first;
        que.pop();
        ll ti = 0;
        if(now.second != -1){
            ti = bitdp[s][pos];
            if(ti == 1e18) continue;
        }
        REP(i,0,n){
            if((s & (1<<i)) == 0){
                if(lis[pos][i].second.second > ti){
                    if(bitdp[s + (1<<i)][i] == 1e18) que.push(Pll(s + (1<<i), i);
                    chmin(bitdp[s + (1<<i)][i], ti + lis[pos][i].second.first);
                }
            }
        }
    }
    ll ans = 1e18;
    ll count = 0;
}