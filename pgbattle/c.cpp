// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

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

const ll mod = 1e9 + 7;

int main(){
    ll n, m, d; cin >> n >> m >> d;
    vector<ll> alis(m), dmod(m), divide(m);
    map<ll, vector<ll>> mp;
    REP(i, 0, m){
        cin >> alis[i];
        dmod[i] = alis[i] % d;
        divide[i] = alis[i] / d;
        if(mp.count(dmod[i])){
            vector<ll> k = mp[dmod[i]];
            k.pb(divide[i]);
            mp[dmod[i]] = k;
        }else{
            vector<ll> k;
            k.pb(divide[i]);
            mp[dmod[i]] = k;
        }
    }
    ll ans = 0;
    ll mod6 = modinv(6, mod);
    for(auto x:mp){
        vector<ll> lis = x.second;
        sort(ALL(lis));
        lis.pb((n / d)+1);
        ll pre = -1;
        REP(i, 0, lis.size()){
            ll c = lis[i] - pre;
            if(c-2 >= 0){
                ans += ((((((c % mod) * (c+1))%mod) * (2*c+1))%mod) * mod6) % mod;
                ans %= mod;
            }
            pre = lis[i];
        }
    }
    cout << ans << endl;
}