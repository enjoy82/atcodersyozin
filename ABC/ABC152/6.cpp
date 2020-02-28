#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MOD = 1000000007; //mod宣言


long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    ll k = 1;
    for(int i = 0; i < n; i++){
        cin >> lis[i];
        k = (lcm(k, lis[i]) % MOD);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += k * modinv(lis[i], MOD);
        ans = ans % MOD;
    }
    cout  << ans << endl;
}