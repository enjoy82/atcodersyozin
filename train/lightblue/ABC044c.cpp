#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, a; cin >> n >> a;
    vector<ll> lis(n+1, 0);
    REP(i, 0, n){cin >> lis[i+1];}
    vector<vector<vector<ll> > > dp(n+1, vector<vector<ll>>(n+1, vector<ll>(3000, 0)));
    REP(i, 0, n+1){
        dp[i][0][0] = 1;
    }
    REP(i, 0, n+1){
        REP(l, 1, n+1){
            REP(k, 0, 3000){
                if(i-1 >= 0 && l-1 >= 0 && k-lis[i] >= 0){
                    dp[i][l][k] = dp[i-1][l][k] + dp[i-1][l-1][k-lis[i]]; 
                }else if(i >= 1){
                    dp[i][l][k] = dp[i-1][l][k];
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        //cout << "#" << i  << " " << dp[i][i][a*i] << endl;
        ans += dp[n][i][a*i];
    }
    cout << ans << endl;
}