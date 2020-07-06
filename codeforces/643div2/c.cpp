#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    vector<ll> up(2e6, 0), down(2e6, 0), imos(2e6, 0), ruiseki(2e6, 0);
    REP(i, a, b+1){
        up[i + b]++;
        down[i + c]++;
    }
    ll count = 0;
    REP(i, 0, 2e6){
        count += up[i];
        imos[i] = count;
        count -= down[i];
    }
    ll ans = 0;
    ll f = (b-a+1) * (c-b+1);
    REP(i, 1, 2e6){
        ruiseki[i] = ruiseki[i-1] + imos[i];
        //cout << ruiseki[i] << endl;
    }
    REP(i, c, d+1){
        ans += f - ruiseki[i];
    }
    cout << ans << endl;
}