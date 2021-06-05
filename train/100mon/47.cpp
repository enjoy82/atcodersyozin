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

int n;
vector<vector<ll> > dp;
vector<ll> alis;

ll solve(int l, int r){
    if(r-l >= n-1) return 0;

    if(dp[l][r] != -1){
        return dp[l][r];
    }
    ll res = 0;
    if((r-l) % 2 == 0){ //IOI
        if(alis[l-1] > alis[r+1])
            res = solve(l-1, r);
        else
            res = solve(l, r+1);
    }else{ //JOI
        res = max(solve(l-1, r) + alis[l-1], solve(l, r+1) + alis[r+1]);
    }
    return dp[l][r] = res;
}


int main(){
    cin >> n;
    dp = vector<vector<ll>>(3*n, vector<ll>(3*n, -1));
    alis = vector<ll>(3*n);
    REP(i,0,n){
        cin >> alis[i];
        alis[n+i] = alis[i];
        alis[2*n+i] = alis[i];
    }
    ll ans = 0;
    REP(i,n,2*n){
        chmax(ans, solve(i, i) + alis[i]);
    }
    cout << ans << endl;
}