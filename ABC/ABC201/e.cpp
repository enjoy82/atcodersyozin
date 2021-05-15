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

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
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

const ll mod = 1e9 + 7;

int main(){
    int n; cin >> n;
    vector<vector<Pll> > tree(n);
    REP(i,0,n-1){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        tree[a].pb(Pll(b,c));
        tree[b].pb(Pll(a,c));
    }
    vector<ll> dist(n, -1);
    dist[0] = 0;
    queue<ll> que;
    que.push(0);
    while(!que.empty()){
        ll now = que.front();
        que.pop();
        REP(i,0,tree[now].size()){
            int next = tree[now][i].first;
            if(dist[next] == -1){
                que.push(next);
                dist[next] = dist[now] ^ tree[now][i].second;
            }
        }
    }
    ll ans = 0;
    vector<vector<ll>> bit(60, vector<ll>(2, 0));
    for(ll i = n-1; i >= 0; i--){
        REP(l,0,60){
            if((dist[i] & (1ll << l)) == 0){
                ans += (((1ll<<l) % mod) * (bit[l][1] % mod))%mod;
                ans %= mod;
                bit[l][0]++;
            }else{
                ans += (((1ll<<l) % mod) * (bit[l][0] % mod))%mod;
                ans %= mod;
                bit[l][1]++;
            }
        }
    }
    cout << ans << endl;
}