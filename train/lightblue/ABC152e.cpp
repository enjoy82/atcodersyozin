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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll mod = 1e9+7;

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % mod, n / 2);
  else
    return x * Pow(x, n - 1) % mod;
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
    int n; cin >> n;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    map<ll, ll> ALLmp;
    REP(i, 0, n){
        map<ll, ll> vmp;
        int k = 2;
        ll c = lis[i];
        while(k * k <= c){
            if(c % k == 0){
                vmp[k]++;
                c /= k;
            }else{
                k++;
            }
        }
        vmp[c]++;
        for(auto &x: vmp){
            chmax(ALLmp[x.first], x.second);
        }
    }
    ll sum = 1;
    for(auto &x: ALLmp){
        sum *= Pow(x.first, x.second);
        sum %= mod;
    }
    ll ans = 0;
    REP(i, 0, n){
        ans += sum * modinv(lis[i], mod);
        ans %= mod;
    }
    cout << ans << endl;
}