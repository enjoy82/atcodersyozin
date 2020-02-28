#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 1000000000;
    for(int i = k-1; i < n; i++){
        ll res = abs(a[i-k+1] - a[i]) + abs(0-a[i-k+1]);
        ll res1 = abs(a[i-k+1] - a[i]) + abs(0-a[i]);
        //cout << res << endl;
        ans = min(res, min(ans, res1));
    }
    cout << ans << endl;
}