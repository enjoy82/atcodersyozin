#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<ll> lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    sort(lis.begin(), lis.end(), greater<>());
    ll ans = 0;
    if(n <= k){cout << 0 << endl; return 0;}
    for(int i = k; i < n; i++){
        ans += lis[i];
    }
    cout << ans << endl;
}