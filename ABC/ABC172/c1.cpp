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
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> alis(n+1), blis(m+1);
    REP(i, 0, n){
        cin >> alis[i+1];
    }
    REP(i, 0, m){
        cin >> blis[i+1];
    }
    REP(i, 0, n){
        alis[i+1] = alis[i+1] + alis[i];
    }
    REP(i, 0, m){
        blis[i+1] = blis[i+1] + blis[i];
    }
    ll ans = 0;
    REP(i, 0, n+1){
        ll c = k - alis[i];
        if(c < 0){
            break;
        }
        auto It = upper_bound(ALL(blis), c);
        ll mid  = i + ((It - blis.begin()) - 1);
        ans = max(mid, ans);
    }
    cout << ans << endl;
}