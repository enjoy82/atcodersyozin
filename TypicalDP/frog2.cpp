#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 10000000
#define INF 10000000000

int main(){
    int n, k; cin >> n >> k;
    vector<ll> dp(n, INF);
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int l = 1; l <= min(i, k); l++){
            dp[i] = min(dp[i-l] + abs(a[i-l] - a[i]), dp[i]); 
        }
    }
    cout << dp[n-1] << endl;
}