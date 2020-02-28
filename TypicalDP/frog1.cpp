#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 10000000
#define INF 100000000

int main(){
    int n; cin >> n;
    int a[n];
    vector<ll> dp(n, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[1] = abs(a[0] - a[1]);
    for(int i = 1; i < n; i++){
        dp[i] = min(dp[i-1] + abs(a[i] - a[i-1]), dp[i-2] + abs(a[i] - a[i-2]));
    }
    cout << dp[n-1] << endl; 
}