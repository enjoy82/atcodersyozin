#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll mod = 1e9 + 7;

const ll MOD = 1e9+7;

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % MOD, n / 2);
  else
    return (x * Pow(x, n - 1)) % MOD;
}

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


int main(){
    ll n; cin >> n;
    map<Pll, ll> mp;
    REP(i, 0, n){
        ll a, b; cin >> a >> b;
        ll k = gcd(abs(a), abs(b));
        a /= k, b /= k;
        mp[Pll(a, b)]++;
    }
    vector<ll> anslis;
    for(auto &p: mp){
        Pll pp = p.first;
        ll a = pp.first, b = pp.second;
        ll count = p.second;
        count += mp[Pll(-1*b, a)];
        count += mp[Pll(b, -1*a)];
        mp[Pll(-1*b, a)] = 0;
        mp[Pll(b, -1*a)] = 0;
        mp[Pll(a, b)] = 0;
        if(count != 0)
            anslis.pb(count);
    }
    ll ans = Pow(2, n) - 1;
    vector<ll> lis(anslis.size());
    ll key = 1;
    REP(i, 0, anslis.size()){
        key = (key * (anslis[i] + 1)) % MOD;
    }
    cout << key-1 << endl;
}