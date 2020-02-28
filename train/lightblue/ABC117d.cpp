#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> lis(n), b(41);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
        ll c = lis[i];
        int res = 0;
        while(c > 0){
            b[res] += c & 1;
            c /= 2; res++;
        }
    }
    ll ans = 0, x = 0;
    for(int i = 40; i >= 0; i--){
        if((x + (1LL << i)) > k){
            continue;
        }
        if(n - b[i] > b[i]){
            x += 1LL << i;
        }
    }
    for(int i = 0; i < n; i++){
        ans += x ^ lis[i];
    }
    cout << ans << endl;
}