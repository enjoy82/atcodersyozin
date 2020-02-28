#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 10000000
#define INF 100000000

int main(){
    int n; cin >> n;
    vector<int> dp(10000);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int mid; cin >> mid;
        for(int l = 10000; l >= 0; l--){
            if(dp[l] == 1){
                //cout << l << endl;
                dp[l+mid] = 1;
            }
        }
        dp[mid] = 1;
    }
    int ans = 0;
    for(int i = 0; i < 10000; i++){
        if(dp[i] == 1){
            ans++;
        }
    }
    cout << ans << endl;
}