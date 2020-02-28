#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll a){
    string aa = to_string(a);
    vector<vector<ll> > dp(32,vector<ll>(2, 0LL));
    int k = aa[0] - '0';
    if(k == 9){
        dp[0][0] = 8;
    }else if(k > 4){
        dp[0][0] = k-1;
        dp[0][1] = 1;
    }else if(k == 4){
        dp[0][0] = k;
    }else{
        dp[0][0] = k;
        dp[0][1] = 1;
    }
    for(int i = 1; i < aa.size(); i++){
        k = aa[i] - '0';
        if(k == 9){
            dp[i][0] = (dp[i-1][0]+dp[i-1][1]) * 8;
        }else if(k > 4){
            dp[i][0] = dp[i-1][0] * 8 + dp[i-1][1] * (k-1);
            dp[i][1] = dp[i-1][1];
        }else if(k == 4){
            dp[i][0] = dp[i-1][0] * 8 + dp[i-1][1] * 4;
        }else{
            dp[i][0] = dp[i-1][0] * 8 + dp[i-1][1] * k;
            dp[i][1] = dp[i-1][1];
        }
    }
    return a - (dp[aa.size()-1][0] + dp[aa.size()-1][1]);
}

int main(){
    ll a, b; cin >> a >> b;
    cout << solve(b) - solve(a-1) << endl;
}