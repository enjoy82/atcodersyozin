#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 10000000
#define INF 10000000000

int main(){
    int n, w; cin >> n >> w;
    int w[n];
    int v[n];
    vector<vector<int> > dp(w+1, vector<int>(n+1, 0));
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= w; i++){
        for(int l = 1; l <= n; l++){
            //dp[i+1][l] = max(dp[i+1][l], dp[i][l]+v[i]);
        }
    }
}