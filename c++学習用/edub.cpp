# include<iostream>
# include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<long long int> a(n);
    vector<long long int> dp(n,10000*1000000);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    dp[0] = 0;dp[1] = abs(a[1]-a[0]);
    for(int i=2;i<n;i++){
        int c = min(i, k);
        for(int l=1; l <= c;l++){
            dp[i] = min(dp[i], dp[i-l]+abs(a[i]-a[i-l]));
        }
    }
    cout << dp[n-1] << endl;
}