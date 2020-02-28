#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 10000000
#define INF 10000000000

int main(){
    int n; cin >> n;
    vector<vector <ll> > dp(n, vector<ll>(3));
    int a, b, c; cin >> a >> b >> c;
    dp[0][0] = a;dp[0][1] = b; dp[0][2] = c;
    for(int i = 1; i < n; i++){
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        for(int l = 0; l < 3; l++){
            for(int k = 0; k < 3; k++){
                if(l == k){continue;}
                dp[i][l] = max(dp[i-1][k]+ a[l], dp[i][l]);
            }
        }
        /*for(int m = 0; m < 3; m++){
            cout << dp[i][m] << " " ;
        }
        cout << endl;*/
    }
    ll ans = 0;
    for(int i = 0; i < 3; i++){
        ans = max(ans, dp[n-1][i]);
    }
    cout << ans << endl;
}