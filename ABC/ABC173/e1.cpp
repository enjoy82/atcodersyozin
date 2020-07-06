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


const ll mod = 1e9 + 7;

long long modinv(long long a) {
    ll m = mod;
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u % m;
}

int main(){
    ll n, k; cin >> n >> k;
    vector<vector<ll>> alis(n, vector<ll>(2, 0));
    ll cc = 0;
    REP(i, 0, n){
        cin >> alis[i][0];
        alis[i][1] = abs(alis[i][0]);
        cc += (alis[i][0] < 0);
    }
    
    sort(ALL(alis), [](auto &x, auto &y){return x[1] > y[1];});
    if(cc == n && k %2 == 1){
        ll ans = 1;
        REP(i, 0, k){
            ans *= alis[n-1-i][1];
            ans %= mod;
        }
        cout << ( (ans * -1) + mod )%mod << endl;
        return 0;
    }
    ll ans = 1, count = 0;
    REP(i, 0, k){
        ans *= alis[i][1];
        ans %= mod;
        if(alis[i][0] < 0){
            count++;
        }
    }
    if(count % 2 == 0){
        cout << ans << endl;
        return 0;
    }else{
        ll fans = 0;
        ll mid1 = ans, mid2 = ans;
        int f1 = 0, f2 = 0;
        ll sub1 = -1, sub2 = -1, key1, key2;
        for(int i = k-1; i >= 0; i--){// + to -
            if(alis[i][0] > 0){
                REP(l, k, n){
                    if(alis[l][0] < 0){
                        sub1 = alis[l][1];
                    }
                    break;
                }
                if(sub1 == -1){
                    break;
                }
                mid1 *= modinv(alis[i][1]);
                key1 = alis[i][0];
                mid1 %= mod;
                mid1 *= sub1;
                mid1 %= mod;
                f1 = 1;
                break;
            }
        }
        if(f1 == 1){
            fans = mid1;
        }
        for(int i = k-1; i >= 0; i--){// - to +
            if(alis[i][0] < 0){ 
                REP(l, k, n){
                    if(alis[l][0] > 0){
                        sub2 = alis[l][1];
                    }
                    break;
                }
                if(sub2 == -1){
                    break;
                }
                mid2 *= modinv(alis[i][1]);
                key2 = alis[i][0];
                mid2 %= mod;
                mid2 *= sub2;
                mid2 %= mod;
                f2 = 1;
                break;
            }
        }
        if(f2 == 1){
            if(f1 == 0){
                fans = mid2;
            }else{
                if(abs(key1 * sub2) <= abs(key2  * sub1)){
                    fans = mid2;
                }
            }
        }
        cout << fans % mod << endl;
    }
}
