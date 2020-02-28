#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    ll x; cin >> x;
    ll ans = 0;
    vector<ll> a(n);
    for(int  i = 0; i < n; i++){
        cin >> a[i];
    }
    if(a[0] > x){
        ans += a[0] - x;
        a[0] -= a[0] - x;
    }
    for(int i = 1; i < n; i++){
        if(a[i-1] + a[i] > x){
            ans += a[i-1] + a[i] - x;
            a[i] -= a[i-1] + a[i] - x;
        }
    }
    cout << ans << endl;
}