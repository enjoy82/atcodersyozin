#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

const ll mod = 1e9 + 7;

ll RepeatSquaring(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2);
        return t*t % mod;
    }
    return ((N * RepeatSquaring(N, P-1)) % mod);
}


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, k; cin >> n >> k;
    vector<ll> lis(k+1, 1);
    REP(i, 1, k+1){
        ll c = k / i;
        lis[i] = RepeatSquaring(c, n);
    }
    ll ans = 0;
    for(int i = k; i >= 1; i--){
        ll mid = lis[i];
        for(int l = i + i; l < k+1; l += i){
            mid = (mid - lis[l] + mod) % mod;
        }
        lis[i] = mid;
        ans = (ans + (mid * i % mod))%mod;
    }
    cout << ans << endl;
}