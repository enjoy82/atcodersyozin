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
    ll n; cin >> n;
    vector<ll> alis(n+1), blis(n), clis(n+1);
    REP(i, 0, n+1){cin >> alis[i];}
    REP(i, 0, n){cin >> blis[i];}
    clis = alis;
    for(int i = n-1; i >= 0; i--){
        ll pre = alis[i+1];
        alis[i+1] = max(alis[i+1] - blis[i], 0LL);
        blis[i] -= (pre - alis[i+1]);
        pre = alis[i];
        alis[i] = max(alis[i] - blis[i], 0LL);
        blis[i] -= (pre - alis[i]);
    }
    ll ans = 0;
    REP(i, 0, n+1){
        ans += abs(clis[i] - alis[i]);
    }
    cout << ans << endl;
}