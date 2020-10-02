#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

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
    ll n, z, w; cin >> n >> z >> w;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    vector<vector<ll> > dp(n+1, vector<ll>(2));
    for(int i = n-1; i >= 0; i--){
        dp[i][0] = -1 * 1e9;
        ll a = (i ? lis[i-1] : w);
        chmax(dp[i][0], abs(a - lis[n-1]));
        REP(l, i+1, n) chmax(dp[i][0], dp[l][1]);

        dp[i][1] = 1e9;
        a = (i ? lis[i-1] : z);
        chmin(dp[i][1], abs(a - lis[n-1]));
        REP(l, i+1, n) chmin(dp[i][1], dp[l][0]);
    }
    cout << dp[0][0] << endl;
}