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

void solve(){
    ll n, k; cin >> n >> k;
    ll l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    if((l1 >= l2 && l1 <= r2) || (r1 >= l2 && r1 <= r2) || (l2 >= l1 && l2 <= r1) || (r2 >= l1 && r2 <= r1)){
        k -= (min(r1, r2) - max(l1, l2)) * n;
        if(k <= 0){
            cout << 0 << endl;
            return;
        }
        ll ans = 0;
        ll l = min(l1, l2), r = max(r1, r2);
        ll add = (max(l1, l2) - l) + (r - min(r1, r2));
        REP(i, 0, n){
            ll pre = k;
            k = max(0LL, k - add);
            if(k == 0){
                ans += pre - k;
            }else{
                ans += add;
            }
        }
        if(k > 0){
            ans += k * 2;
        }
        cout << ans << endl;
    }else{
        ll ans = 0;
        ll ans1 = 1e16;
        if(l1 > l2){
            ll x = l2; l2 = l1; l1 = x;
            x = r2; r2 = r1; r1 = x;
        }
        REP(i, 0, n){
            ll cl1 = l1, cl2 = l2, cr1 = r1, cr2 = r2;
            ans += (cl2 - cr1);
            cr1 = cl2;
            ll add =  (cl2 - cl1) + (cr2 - cl2);
            ll pre = k;
            k = max(0LL, k - add);
            if(k == 0){
                ans += pre - k;
            }else{
                ans += add;
            }
            if(k > 0){
                chmin(ans1, ans + (k * 2));
            }else if(k == 0){
                chmin(ans1, ans);
            }
        }
        cout << ans1 << endl;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}