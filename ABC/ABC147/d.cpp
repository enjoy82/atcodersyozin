#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 1000000007;

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    ll mid = 0;
    for(int i = 0; i < n; i++){
        cin >> lis[i];
        mid = mid ^ lis[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (mid ^ lis[i]) % mod;
    }
    cout << ans << endl;
}