#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n; cin >> n;
    ll ans = 0;
    vector<ll> alis(n), blis(n), clis(n);
    REP(i, 0, n){
        cin >> alis[i] >> blis[i];
    }
    for(int i = n-1; i >= 0; i--){
        ll aa = alis[i] + ans;
        ll cc = aa % blis[i];
        if(cc != 0){cc = blis[i] - cc;}
        ans += cc;
    }
    cout << ans << endl;
}