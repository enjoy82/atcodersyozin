#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> dp(100010);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        for(int l = 6; l <= i; l*=6){
            if(dp[i] > dp[i-l]){
                dp[i] = min(dp[i], dp[i-l]+1);
            }
        }
       for(int l = 9; l <= i; l*=9){
            if(dp[i] > dp[i-l]){
                dp[i] = min(dp[i], dp[i-l]+1);
            }
        } 
    }
    cout << dp[n] << endl;
}