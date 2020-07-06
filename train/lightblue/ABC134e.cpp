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

#define MAX_N 100000
#define INF 1e+13
ll dp[MAX_N];
ll n;
vector<ll> lis;

void solve() {
    fill(dp, dp+n, INF);
    for (int i=0; i<n; ++i) {
        *upper_bound(dp, dp+n, lis[i]) = lis[i];
    }
    cout << lower_bound(dp, dp+n, INF) - dp << endl;
}

int main() {
    cin >> n;
    lis.resize(n);
    for(int i=0; i<n; ++i) cin >> lis[i];
    reverse(ALL(lis));
    solve();
}