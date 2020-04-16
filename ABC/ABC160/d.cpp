#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, x, y; cin >> n >> x >> y;
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++){
        for(int l = 1; l <= n; l++){
            dp[i][l] = abs(i - l);
            if(i < l){
                dp[i][l] = min(dp[i][l], abs(x-i) + 1 + abs(l-y));
            }
            if(x <= i && y >= i){
                    int k = abs(i - x) + 1 + abs(l - y);
                    int k1 = abs(i-y) + 1 + abs(l - x);
                    dp[i][l] = min({dp[i][l], k, k1});
            }
            if(l < i){
                dp[i][l] = min(dp[i][l], abs(i - y) + 1 + abs(l-x));
            }
        }
    }
    vector<int> lis(n+1, 0);
    for(int i = 1; i <= n; i++){
        for(int l = 1; l <= n; l++){
            lis[dp[i][l]] += 1;
            //cout << dp[i][l];
        }
        //cout << endl;
    }
    for(int i = 1; i <= n-1; i++){
        cout << lis[i]  /2 << endl;
    }
}