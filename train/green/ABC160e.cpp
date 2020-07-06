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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<ll> plis(a), qlis(b), rlis(c), anslis;
    REP(i, 0, a){cin >> plis[i];}
    REP(i, 0, b){cin >> qlis[i];}
    REP(i, 0, c){cin >> rlis[i];}
    sort(ALL(plis), greater<>());
    sort(ALL(qlis), greater<>());
    sort(ALL(rlis), greater<>());
    REP(i, 0, x){
        anslis.pb(plis[i]);
    }
    REP(i, 0, y){
        anslis.pb(qlis[i]);
    }
    REP(i, 0, min(x+y, c)){
        anslis.pb(rlis[i]);
    }
    sort(ALL(anslis), greater<>());
    ll ans = 0;
    REP(i, 0, x+y){
        ans += anslis[i];
    }
    cout << ans << endl;
}