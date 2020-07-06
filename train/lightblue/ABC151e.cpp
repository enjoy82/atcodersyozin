#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

const ll MAX = 2000000; //テーブルの数
const ll MOD = 1e9+7; //mod宣言

long long fac[MAX], finv[MAX], inv[MAX];
// finv ->階乗割り算
// fac ->階乗掛け算

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;
}

int main(){
    COMinit();
    ll n, k; cin >> n >> k;
    vector<ll> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
    }
    sort(ALL(lis));
    ll mi = 0;
    ll ma = 0;
    REP(i, 0, n-k+1){
        if(lis[i] >= 0){
            mi = (mi + (lis[i] * COM(n-(i+1), k-1))%MOD) % MOD;
        }else{
            ma = (ma + ((-1 * lis[i]) * COM(n-(i+1), k-1))%MOD) % MOD;
        }
    }
    sort(ALL(lis), greater<>());
    
    REP(i, 0, n-k+1){
        if(lis[i] >= 0){
            ma = (ma + (lis[i] * COM(n-(i+1), k-1))%MOD) % MOD;
        }else{
            mi = (mi + ((-1 * lis[i]) * COM(n-(i+1), k-1))%MOD) % MOD;
        }
    }
    cout << (ma - mi + MOD) % MOD << endl;
    return 0;
}