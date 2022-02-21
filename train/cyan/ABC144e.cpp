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

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> alis(n), flis(n);
    ll ans = 0;
    REP(i, 0, n){cin >> alis[i];}
    REP(i, 0, n){cin >> flis[i];}
    sort(ALL(alis));
    sort(ALL(flis), greater<>());
    ll right = 0, left = 1e14;
    while(left-right > 1){
        ll ck = k;
        ll mid = (right+left) / 2;
        //cout << mid << endl;
        REP(i, 0, n){
            ll cc = mid / flis[i];
            ck -= max(alis[i]-cc, 0LL);
        }
        if(ck >= 0){
            left = mid;
        }else{
            right = mid;
        }
    }
    ll ck = k;
    ll mid = left;
    REP(i, 0, n){
        ll cc = mid / flis[i];
        ck -= max(alis[i]-cc, 0LL);
    }
    if(ck > 0){
        REP(i, 0, n){
            ll cc = mid / flis[i];
            ans = max(ans, cc * flis[i]);
        }
    }
    cout << ans << endl;
}