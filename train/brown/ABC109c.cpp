#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> lis(n), lis2(n);
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 0, n){
        lis2[i] = abs(lis[i] - x);
    }
    sort(ALL(lis2));
    ll ans = lis2[0];
    REP(i, 1, n){
        ans = gcd(ans, lis2[i]);
    }
    cout << ans << endl;
}