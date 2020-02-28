#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 10000000
#define INF 100000000

int main(){
    int n, ma, mb; cin >> n >> ma >> mb;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        int d, e, f; cin >> d >> e >> f;
        a[i] = d;b[i] = e; c[i] = f;
    }
    int dp[n][1000][1000];
    for(int i = 0; i < n; i++){
        for(int l = 0; l < 1000; l++){
            for(int m = 0; m < 1000; m++){
                dp[i][l][m] = 1000000;
                cout << "ok" << endl;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i < n-1; i++){
        for(int l = 0; l < 1000; l++){
            for(int m = 0; m < 1000; m++){
                dp[i+1][l][m] = min(dp[i+1][l][m], dp[i][l][m]); //dp down
                dp[i+1][l+a[i]][m+b[i]] = min(dp[i+1][l+a[i]][m+b[i]], dp[i][l][m]+c[i]); // r is unchange, l is update
                cout << dp[i+1][l][m]<<dp[i+1][l+a[i]][m+b[i]] <<endl;
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < n; i++){
        for(int l = 0; l < 1000; l++){
            for(int m = 0; m < 1000; m++){
                if(dp[i][l][m] != 10000 && l*mb == m *ma && ans > dp[i][l][m]){
                    ans = dp[i][l][m];
                }
            }
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}