#include<iostream>
#include <algorithm>
using namespace std;

int w, n, k;
int a[50], b[50];
int dp[51][10001][51];

int saiki(int l, int wid, int K){
    int ret;
    if(dp[l][wid][K] != 0){
        return dp[l][wid][K];
    }else if(l == n){
        return 0;
    }else if(wid < a[l] || K == 0){
        ret = saiki(l+1, wid, K);
    }else{
        ret = max(saiki(l+1, wid, K), saiki(l+1, wid-a[l], K-1)+b[l]);
    }
        dp[l][wid][K] = ret;
        return ret;
}
int main(){
    cin >> w >> n >> k;
    for(int i =0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    cout << saiki(0, w, k) << endl;
}