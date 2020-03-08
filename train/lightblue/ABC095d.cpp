#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, c; cin >> n >> c;
    vector<vector<ll> > lis(n+1, vector<ll>(2, 0)), lis2(n+1, vector<ll>(2, 0));
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        lis[i+1][0] = a;
        lis[i+1][1] = lis[i][1] + b;
        sum += b;
    } 
    for(int i = 0; i < n; i++){
        lis2[i+1][0] = c - lis[n-i][0];
        lis2[i+1][1] = sum - lis[n-i-1][1];
        cout << lis2[i+1][0] << lis2[i+1][1] << endl;
    }
    vector<ll> mab(n+1, 0);
    for(int i = 1; i < n+1 ; i++){
        mab[i] = max(mab[i-1], lis2[i][1] - lis2[i][0]);
        cout << mab[i] << endl;
    }
    ll ans = 0;
    for(int i = 0; i < n+1; i++){
        ll mid = lis[i][1] - lis[i][0];
        ll mid3 = lis2[i][1] - lis2[i][0];
        ll mid2 = mid + mab[n-i] - lis[i][0];
        ans = max({ans, mid, mid2});
    }
    cout << ans << endl;
}