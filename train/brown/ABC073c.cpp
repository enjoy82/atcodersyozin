#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    map<ll, ll> m;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        m[a]++;
    }
    int ans = 0;
    for(auto &x: m){
        ans += (x.second % 2);
    }
    cout << ans << endl;
}