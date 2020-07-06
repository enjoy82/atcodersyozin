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
    ll n, d, a; cin >> n >> d >> a;
    vector<vector<ll> > lis(n, vector<ll>(2, 0));
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1];
    }
    sort(ALL(lis), [](auto &x, auto &y){return x[0] < y[0];});
    vector<ll> ruisekidown(n, 0), idx(n, 0);
    REP(i, 0, n){
        idx[i] = lis[i][0];
    }
    ll ans = 0;
    ll dam = 0;
    REP(i, 0, n){
        dam -= ruisekidown[i];
        if(dam >= lis[i][1]){
            continue;
        }
        ll c = (lis[i][1] - dam + (a-1))/a;
        ans += c;
        dam += c * a;
        auto it = upper_bound(ALL(idx), 2*d + lis[i][0]);
        int next = it-idx.begin();
        if(next == n){continue;}
        ruisekidown[next] += c * a;
    }
    cout << ans << endl;
}