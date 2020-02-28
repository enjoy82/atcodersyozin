#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> dp(51);
vector<ll> dp2(51);

ll solve(ll n, ll x){
    if(n == 0){
        if(x >= 1)
            return 1;
        else
            return 0;
    }else if(x > dp2[n-1]+1){
        return 1 + dp[n-1] + solve(n-1, x - dp2[n-1] - 2);
    }else{
        return solve(n-1, x-1);
    }
}
int main(){
    ll n, x; cin >> n >> x;
    dp[0] = 1;
    dp2[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1]*2 + 1;
        dp2[i] = dp2[i-1]*2 + 3;
    }
    ll ans = solve(n, x);
    cout << ans << endl;
}