#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    double ans = 0;
    int n, k;
    cin >> n >> k;
    int a[n];
    int dp[n][n];
    for(int i=0;i<n;i++){
        double mid;
        cin >> mid;a[i] = mid;dp[i][i] = mid;
        if(mid >= k){ans +=1;}
    }
    for(int l = 0; l<n; l++){
        for(int m =l+1; m<n; m++){
            dp[l][m] = dp[l][m-1] + a[m];
            if(dp[l][m]>= k){
                ans +=1;
            }
        }
    }
    cout << ans;
}