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
    vector<ll> lis(n, 0), dp(n, 0);
    REP(i, 0, n){cin >> lis[i];}
    dp[0] = 0; dp[1] = abs(lis[1] - lis[0]);
    REP(i, 2, n){
        dp[i] = min(dp[i-1]+abs(lis[i]-lis[i-1]), dp[i-2]+abs(lis[i]-lis[i-2]));
        //cout << dp[i] << endl;
    }
    cout << dp[n-1] << endl;
}