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

int main(){
    ll n, m; cin >> n >> m;
    vector<Pll> lis(m);
    REP(i,0, m){
        ll a, b; cin >> a >> b;
        lis[i] = Pll(a, b);
    }
    vector<Pll> so;
    map<ll, ll> noso;
    REP(i,0,m){
        if(gcd(n, lis[i].first) == 1){
            so.pb(lis[i]);
        }else{
            if(noso.count(gcd(n, lis[i].first))){
                chmin(noso[gcd(n, lis[i].first)], lis[i].second);
            }else{
                noso[gcd(n, lis[i].first)] = lis[i].second;
            }
        }
    }
    sort(ALL(so), [](auto &x, auto &y){return x.second < y.second;});
    ll ans = 1e18 + 5e17;
    REP(i,0,so.size()){
        chmin(ans, so[i].second * (n-1));
    }
    for(auto x: noso){
        ll gc = gcd(max(x.first, n), min(x.first, n));
        ll c1 = x.second * (n - gc);
        ll c2 =  1e18 + 5e17;
        if(so.size() != 0)
            c2 = so[0].second * (gc - 1);
        
        for(auto y:noso){
            if(gcd(max(x.first, y.first), min(x.first, y.first)) == 1)
                chmin(c2, y.second * (gc - 1));
        }
        
        chmin(ans, c1 + c2);
    }

    if(ans == 1e18 + 5e17){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}