#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll> > lis(n, vector<ll>(2, 0));
    for(int i = 0; i < n; i++){
        cin >> lis[i][0] >> lis[i][1];
    }
    sort(lis.begin(), lis.end(), [](auto &x, auto &y){return x[0] < y[0];});
    ll ans = 0;
    int i = 0;
    while(m > 0){
        ans += lis[i][0] * min(m, lis[i][1]);
        m -= lis[i][1];
        i++;
    }
    cout << ans << endl;
}