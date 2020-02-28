#include<iostream>
#include <algorithm>
using namespace std;


int main(){
    int dp[10001];
    dp[0] = 1;
    int n;cin >> n;
    int a[n];
    int ans;
    for(int i=0; i<n;i++){
        cin >> a[i];
    }
    for(int l = 0;l<n; l++){
         for(int i = 10000; i >= 0; i--){
              if(dp[i] == 1){
                dp[i+a[l]] = 1;
             }
        }
    }
    
}