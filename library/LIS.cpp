#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)

#define MAX_N 100000
#define INF 1e+13
ll dp[MAX_N];
ll n;
vector<ll> lis; //LIS求めるやつ

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
    solve();
}