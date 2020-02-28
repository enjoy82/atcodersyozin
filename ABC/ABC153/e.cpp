#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll INF = 10000000000;

int main(){
    int h, n; cin >> h >> n;
    vector<ll> dp(h + 20000, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        for(int l = 0; l < h + 20000; l++){
            if(l-a >= 0)
                dp[l] = min(dp[l], dp[l-a] + b);
        }
    }
    ll ans = INF;
    for(int i = h; i < h + 20000; i++){
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
}