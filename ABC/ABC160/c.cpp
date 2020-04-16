#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll k, n; cin >> k >> n;
    vector<ll> lis(n, 0);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    ll ma = 0;
    for(int i = 0; i < n-1; i++){
        ma = max(ma, lis[i+1] - lis[i]);
    }
    ma = max(k - lis[n-1] + lis[0], ma);
    cout << k - ma;
}