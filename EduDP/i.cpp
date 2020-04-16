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
    int n; cin >> n;
    vector<vector<ld> > dp(n+3, vector<ld>(n+3, 0));
    ld a; cin >> a;
    dp[1][1] = a;
    dp[1][0] = (1-a);
    REP(i, 1, n){
        cin >> a;
        REP(l, 0, n){
            dp[i+1][l+1] += dp[i][l] * a;
            dp[i+1][l] += dp[i][l] * (1-a);
        }
    }
    ld ans = 0;
    REP(i, n/2+1, n+1){
        ans += dp[n][i];
    }
    cout << fixed << setprecision(20) << ans << endl;
}