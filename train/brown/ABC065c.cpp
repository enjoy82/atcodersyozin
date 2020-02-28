#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n, m; cin >> n >> m;
    if(abs(n-m) >= 2){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(int i = n; i >= 1; i--){
        ans = ans * i % mod;
    }
    for(int i = m; i >= 1; i--){
        ans = ans * i % mod;
    }
    if(n == m){ans = ans * 2%mod;}
    cout << ans << endl;
    return 0;
}