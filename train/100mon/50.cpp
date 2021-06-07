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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, Pll>> > lis(n);
    REP(i,0,m){
        ll s, t, d, ti; cin >> s >> t >> d >> ti;
        s--; t--;
        pair<ll, Pll> e = {t, Pll(d, ti)};
        pair<ll, Pll> e1 = {s, Pll(d, ti)};
        lis[s].pb(e);
        lis[t].pb(e1);
    }
    vector<vector<ll>> bitdp((1ll<<n), vector<ll>(n, 1e18));
    vector<vector<ll>> count((1ll<<n), vector<ll>(n, 0));
    bitdp[1][0] = 0ll;
    count[1][0] = 1;
    ll key = (1ll<<n)-1;
    REP(i,1,(1<<n)){
        REP(l,0,n){
            ll ti = bitdp[i][l];
            if(ti != 1e18){
                REP(k,0,lis[l].size()){
                    ll next = lis[l][k].first;
                    ll sum = ti + lis[l][k].second.first;
                    if((i & (1<<next)) == 0 && (lis[l][k].second.second >= sum)){
                        if(bitdp[i | (1<<next)][next] > sum){
                            bitdp[i | (1<<next)][next] = sum;
                            count[i | (1<<next)][next] = count[i][l];
                        }else if(bitdp[i | (1<<next)][next] == sum){
                            count[i | (1<<next)][next] += count[i][l];
                        }
                    }
                }
            }
        }
    }
    ll ans = 1e18;
    ll count2 = 0;
    
    REP(from,0,n){
        REP(i,0,lis[from].size()){
            ll next = lis[from][i].first;
            ll ti = bitdp[key][from];
            ll sum = ti + lis[from][i].second.first;
            if(next == 0 && lis[from][next].second.second >= sum){
                if(ans > sum){
                    ans = sum;
                    count2 = count[key][from];
                }else if(ans == sum){
                    count2 += count[key][from];
                }else{
                    continue;
                }
            }
        }
    }
    if(ans >= 1e18){
        cout << "IMPOSSIBLE" << endl;
        return 0; 
    }
    cout << ans << " " << count2 << endl;
}