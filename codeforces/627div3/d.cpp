#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n; cin >> n;
    ll ans = 0;
    vector<ll> alis(n), blis(n), clis(n);
    REP(i, 0, n){cin >> alis[i];}
    REP(i, 0, n){cin >> blis[i];}
    REP(i, 0, n){clis[i] = alis[i] - blis[i];}
    sort(ALL(clis));
    for(int i = n-1; i >= 0; i--){
        ll k = clis[i] * -1;
        auto it = upper_bound(ALL(clis), k);
        ll t = max(0, i - (it-clis.begin()));
        ans += t;
    }
    cout << ans << endl;
}