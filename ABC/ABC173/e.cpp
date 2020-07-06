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
    int aa = 0;
    REP(i, 0, n){
        cin >> alis[i][0];
        alis[i][1] = abs(alis[i][0]);
        if(alis[i][0] > 0){
            aa = 1;
        }
    }
    sort(ALL(alis), [](auto &x, auto &y){return x[1] > y[1];});
    ll ans = 1;
    if(n == k || (aa == 0 && (k % 2 == 1))){
        ll ans = 1;
        REP(i, 0, k){
            ans = (ans * alis[n-1-i][0]) % mod;
        }
        cout << (ans + mod)%mod << endl;
        return 0;
    }
    if(k % 2 == 1){
        REP(i, 0, n){
            if(alis[i][0] > 0){
                ans = alis[i][0];
                alis[i][0] = 0;
                alis[i][1] = 0;
                break;
            }
        }
        k--;
        n--;
        sort(ALL(alis), [](auto &x, auto &y){return x[1] > y[1];});
    }
    priority_queue<ll> pq, mq;
    ll ppre = 1e12, mpre = 1e12;
    REP(i, 0, n){
        if(alis[i][0] > 0){
            if(ppre == 1e12){
                ppre = alis[i][1];
            }else{
                pq.push(ppre * alis[i][1]);
                //out << ppre * alis[i][1] << endl;
                ppre = 1e12;
            }
        }else{
            if(mpre == 1e12){
                mpre = alis[i][1];
            }else{
                mq.push(abs(mpre * alis[i][1]));
                //cout << abs(mpre * alis[i][1]) << endl;
                mpre = 1e12;
            }
        }
    }
    REP(i, 0, k/2){
        if( (!pq.empty() && !mq.empty() && pq.top() < mq.top()) || (pq.empty() && !mq.empty())){
            ans = ans * (mq.top())%mod;
            ans %= mod;
            mq.pop();
        }else{
            ans = (ans * (pq.top())%mod) % mod;
            ans %= mod;
            pq.pop();
        }
    }
    cout << ans << endl;
}