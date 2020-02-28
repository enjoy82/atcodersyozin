#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, d, a; cin >> n >> d >> a;
    vector<vector<ll> > lis(n, vector<ll>(2, 0));
    for(int i = 0; i < n; i++){
        cin >> lis[i][0] >> lis[i][1];
    }
    sort(lis.begin(), lis.end(), [](auto &x, auto &y){return x[0] < y[0];});
    ll k = lis[i][0] + 2*d;
    ll pre = lis[i][1];
    for(int i = 0; i < n; i++){
        if(k > lis[i][1])
    }
}