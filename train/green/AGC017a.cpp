#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


/*
// 二項係数計算
long long COM(ll n, ll k){
    //cout << n << k << endl;
    map<ll, ll> mp;
    REP(i, 0, k){
        ll l = 2;
        ll nn = n;
        while(nn >= l * l){
            if(nn % l == 0){
                mp[l]++;
                nn /= l;
            }else{
                l++;
            }
        }
        mp[nn]++;
        n--;
    }
    for(ll i = k; i >= 1; i--){
        ll l = 2;
        ll nn = i;
        while(nn >= l * l){
            if(nn % l == 0){
                mp[l]--;
                nn /= l;
            }else{
                l++;
            }
        }
        mp[nn]--;
    }
    ll ans = 1;
    for(auto &x: mp){
        //ans *= (x.first * x.second);
        if(x.first == 1 || x.second == 0)
            continue;
        ans *= (x.first * x.second);
    }
    return ans;
}
*/


const ll MAX = 150; //テーブルの数
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
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
    COMinit();
    ll n, p; cin >> n >> p;
    ll a1 = 0, a0 = 0;
    vector<ll> lis(n);
    REP(i, 0, n){
        ll a; cin >> a; 
        if(a % 2 == 1){
            a1++;
        }else{
            a0++;
        }
    }
    ll ans = 0;
    //cout << a1 << a0 << endl;
    if(p == 0){
        for(ll i = 0; i <= a1; i+=2){
            ans += COM(a1, i);
        }
        ans *= (ll)pow(2, a0);
    }else{
        for(ll i = 1; i <= a1; i+=2){
            ans += COM(a1, i);
            //cout << COM(a1, i) << endl;
        }
        ans *= (ll)pow(2, a0);
    }
    cout << ans << endl;
}