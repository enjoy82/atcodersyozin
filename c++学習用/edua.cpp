# include<iostream>
# include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> a(n);
    vector<int> dp(n,0);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    dp[0] = 0;dp[1] = abs(a[1]-a[0]);
    for(int l=2;l<n;l++){
        dp[l] = min(dp[l-1]+abs(a[l]-a[l-1]), dp[l-2]+abs(a[l]-a[l-2]));
    }
    cout << dp[n-1] << endl;
}