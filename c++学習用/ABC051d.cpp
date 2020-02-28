#include<bits/stdc++.h>
using namespace std;

int inf = 10000001;

int main(){
    int n, m;cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    vector<int> c(m);
    vector<vector<int> > dp(n+1, vector<int>(n+1));
    for(int i = 0; i<m;++i){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;b[i]--;
    }
    for(int i = 0; i<n;++i){
        for(int l = 0; l < n; ++l){
            if(i == l){dp[i][l] = 0;}
            else{dp[i][l] = inf;}
        }
    }
    for(int i = 0; i<m;++i){
        dp[a[i]][b[i]] = min(dp[a[i]][b[i]], c[i]);
        dp[b[i]][a[i]] = min(dp[b[i]][a[i]], c[i]);
    }
    for(int k = 0; k<n;++k){
        for(int i = 0; i<n;++i){
            for(int l = 0; l<n; ++l){
                dp[i][l] = min(dp[i][l], dp[i][k]+dp[k][l]);
            }
        }
    }
    int ans = m;
    int j = 0;
    for(int i = 0; i<m; ++i){
        j = 0;
        for(int l = 0; l<n; ++l){
            if(dp[l][a[i]] + c[i] == dp[l][b[i]]){j = 1;}   
        }
        if(j == 1){ans--;}
    }
    cout << ans << endl;
}