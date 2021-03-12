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

ll solve1(ll n, ll w, vector<vector<ll> > lis){
    map<ll, ll> mp1, mp2;
    REP(i, 0, (1 << n/2)){
        ll vsum = 0, wsum = 0;
        REP(l,0,n){
            if(i & (1<<l)){
                vsum += lis[l][0];
                wsum += lis[l][1];
            }
        }
        mp1[wsum] = vsum;
    }
    REP(i, 0, (1<<(n+1)/2)){
        ll vsum = 0, wsum = 0;
        REP(l,0,n){
            if(i & (1<<l)){
                vsum += lis[l + n/2][0];
                wsum += lis[l + n/2][1];
            }
        }
        mp2[wsum] = vsum;
    }
    ll premax = 0;
    mp2[0] = 0;
    mp1[0] = 0;
    for(auto &x: mp2){
        chmax(premax, x.second);
        x.second = premax;
    }
    ll ans = 0;
    for(auto &x:mp1){
        ll w_diff = w - x.first;
        if(w_diff < 0){
            continue;
        }
        auto it = mp2.lower_bound(w_diff+1);
        it--;
        chmax(ans, it->second + x.second);
    }
    return ans;
}


//W
ll solve2(ll n, ll w, vector<vector<ll> > lis){
    vector<vector<ll> > dp(n+1, vector<ll>(3e5, -1));
    dp[0][0] = 0;
    REP(i,0,n){
        dp[i+1] = dp[i];
        REP(l,0,3e5){
            if(dp[i][l] != -1 && l+lis[i][1] < 3e5){
                chmax(dp[i+1][l+lis[i][1]], dp[i][l]+lis[i][0]);
            } 
        }
    }
    ll ans = 0;
    REP(i,0,w+1){
        chmax(ans, dp[n][i]);
    }
    return ans;
}

ll solve3(ll n, ll w, vector<vector<ll> > lis){
    vector<vector<ll> > dp(n+1, vector<ll>(3e5, 1e17));
    dp[0][0] = 0;
    REP(i,0,n){
        dp[i+1] = dp[i];
        REP(l,0,3e5){
            if(dp[i][l] != 1e17 && l+lis[i][0] < 3e5){
                chmin(dp[i+1][l+lis[i][0]], dp[i][l]+lis[i][1]);
            } 
        }
    }
    ll ans = 0;
    REP(i,0,3e5){
        if(dp[n][i] <= w){
            ans = i;
        }
    }
    return ans;
}

int main(){
    ll n, w; cin >> n >> w;
    ll wmax = 0, vmax = 0;
    vector<vector<ll> > lis(n, vector<ll>(2));
    REP(i,0,n){
        cin >> lis[i][0] >> lis[i][1];
        chmax(wmax, lis[i][1]);
        chmax(vmax, lis[i][0]);
    }
    if(n<= 30){
        cout << solve1(n, w, lis) << endl;
    }else if(wmax <= 1000){
        cout << solve2(n, w, lis) << endl;
    }else{
        cout << solve3(n, w, lis) << endl;
    }
}