#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll n, w; cin >> n >> w;
    vector<vector<ll> > dp(n+1, vector<ll>(2e5, 1e10));
    REP(i, 0, n+1){dp[i][0] = 0;}
    REP(i, 0, n){
        ll a, b; cin >> a >> b;
        REP(k, 0, b){
            dp[i+1][k] = min(dp[i+1][k], dp[i][k]);
        }
        REP(l, 0, 1e5+1e4){
            dp[i+1][l+b] = min({dp[i+1][l+b], dp[i][l+b], dp[i][l] + a});
        }
    }
    ll ans = 0;
    REP(i, 0, 2e5){
        if(dp[n][i]<=w && dp[n][i] != 1e10){
            ans = i;
        }
    }
    cout << ans << endl;
}