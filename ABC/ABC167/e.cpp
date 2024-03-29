#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

const int MAX = 310000; //テーブルの数
const int MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];
// finv ->階乗割り算
// fac ->階乗掛け算

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow((x * x )  % MOD, n / 2);
  else
    return (x * Pow(x, n - 1)) % MOD;
}


int main(){
    COMinit();
    ll n, m, k; cin >> n >> m >> k;
    ll ans = 0;
    REP(i, 0, k+1){
        ans = (ans + (m%MOD) *((COM(n-1, i) % MOD) * Pow(m-1, n-1-i) % MOD )% MOD) %MOD;
    }
    cout << ans << endl;
}