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

ll ans = 1e18;

int main(){
    int n; cin >> n;
    map<ll, ll> mp;
    vector<vector<ll> > lis(n+1);
    ll r = 0;
    REP(i,0,n){
        ll x, c; cin >> x >> c;
        mp[c] = 1;
        chmax(r, c);
        lis[c].pb(x);
    }
    REP(i,0,n+1){
        if(lis[i].size() > 1){
            sort(ALL(lis[i]));
        }
    }
    //+にいく
    ll nx = 0, mid = 0;
    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    dp[0][0] = 0; //+ pnxにいる
    dp[0][1] = 0; //- mnxにいる
    ll pnx = 0;
    ll mnx = 0;
    ll pre = 0;
    for(auto x: mp){
        ll mid1 = 0, mid2 = 0, mid3 = 0, mid4 = 0;
        mid1 += abs(pnx - lis[x.first][0]);
        mid1 += abs(lis[x.first][0] - lis[x.first].back());

        mid2 += abs(mnx - lis[x.first][0]);
        mid2 += abs(lis[x.first][0] - lis[x.first].back());

        mid3 += abs(pnx - lis[x.first].back());
        mid3 += abs(lis[x.first].back() - lis[x.first][0]);

        mid4 += abs(mnx - lis[x.first].back());
        mid4 += abs(lis[x.first].back() - lis[x.first][0]);

        dp[x.first][0] += min(dp[pre][1] + mid2, dp[pre][0] + mid1);
        dp[x.first][1] += min(dp[pre][0] + mid3, dp[pre][1] + mid4);


        if(x.first == r){
            cout << min(dp[x.first][0] + abs(lis[x.first].back()), dp[x.first][1] + abs(lis[x.first][0]) ) << endl;
            return 0;
        }
        pre = x.first;
        pnx = lis[x.first].back();
        mnx = lis[x.first][0];
    }
}