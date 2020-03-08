#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll a, b, m; cin >> a >> b >> m;
    vector<ll> alis(a+1, 0), blis(b+1, 0);
    ll amin = 1e8, bmin = 1e8;
    for(int i = 0; i < a; i++){
        cin >> alis[i+1];
        amin = min(amin, alis[i+1]);
    }
    for(int i = 0; i < b; i++){
        cin >> blis[i+1];
        bmin  = min(bmin, blis[i+1]);
    }
    vector<vector<ll> > lis(m, vector<ll>(3, 0));
    ll sum = amin + bmin;
    for(int i = 0; i < m; i++){
        ll x, y, z; cin >> x >> y >> z;
        sum = min(sum, alis[x] + blis[y] - z);
    }
    cout << sum << endl;
}