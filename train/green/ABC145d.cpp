#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX = 1100000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

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

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    int x, y; cin >> x >> y;
    int a = 0, b = 0, f = 0;
    for(int i = 0; i <= y; i++){
        a = i;
        b = y - 2*a;
        if(a + 2*b == x){
            f = 1;
            break;
        }else{
            continue;
        }
    }
    if(f == 0){
        cout << 0 << endl;
        return 0;
    }
    COMinit();
    ll ans = COM(a+b, b);
    cout << ans << endl;
}