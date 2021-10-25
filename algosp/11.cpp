#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll message[9] = {1950507198, 2327932771, 3867273736, 1778638487, 2560135757, 700859399, 3108515537, 2459576784, 248377069};

std::string ans = "";

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ull Pow(ull x, ull n, ull MOD){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(((x % MOD) * (x % MOD)) % MOD, n / 2, MOD) % MOD;
  else
    return ((x % MOD) * (Pow(x, n - 1, MOD) % MOD)) % MOD;
}

ll extGcd(ll X, ll Y, ll &p, ll &q) {  
    if (Y == 0) { p = 1; q = 0; return X; }  
    ll d = extGcd(Y, X%Y, q, p);  
    q -= X/Y * p;  
    return d;  
}

ull solve(ull m, ull D, ull mod){
    ull k = Pow(m % mod, D, mod);
    std::string mid = "";
    for(int i = 0; i < 4; i++){
        int num_get = k % (1<<7);
        //cout << num_get << " " << char(num_get) << endl;
        mid = char(num_get) +  mid;
        k = k >> 7;
    }
    ans = ans + mid;
    return k;
}

int main() {
    ll e = 911, p = 63331, q = 65353, n, D, v;
    n = p * q;
    ll L = lcm(p-1, q-1);
    extGcd(e, L, D, v);
    //cout << "extGCD res : " << D << " " << v << endl;
    for(int i = 0; i < 9; i++){
        solve(message[i], D, n);
    }
    cout << ans << endl;
}