#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int n,  m , t; cin >> n >> m >> t;
    vector<int> ans(n, 0);
    vector<int> ans2(n, 0);
    int count = 0, count2 = 0;
    vector<vector<int> > dp(n, vector<int>(n, 0));
    vector<int > a(n);
    for(int i = 0; i < n; i++){
        int mid; cin  >> mid;
        a[i] = mid;
    }
    for(int i = 0; i < m; i++){
        int  a, b, c; cin >> a >> b >> c;
        if(a == 1){ans[b-1] = c; count++;}
        if(b == 1){ans2[a-1] = c; count2++;}
        dp[a-1][b-1] = c;
        dp[b-1][a-1] = c;
    }
    while(count < n-1){

    }
    while(count2 < n-1){

    }
    int ans1 = 
    for(int i = 0; i < n; i++){

    }
}