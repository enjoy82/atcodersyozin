#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;cin >> n;
    int a[n];
    int dp[30001] = {0};
    int ans = 1;
    for(int i=0; i<n;i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int l = 0; l < i ; l++){
            if(a[l] < a[i]){
                dp[i] = max(dp[i], dp[l]+1);
            }
            ans = max(ans, dp[i]);
        }
    }
    cout << n-ans << endl;
    return 0;
}