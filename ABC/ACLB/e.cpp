// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define ll int

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using mint = modint998244353;

struct S {
    mint a;
    int size;
};

struct F {
    mint a, b;
};

S op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }

S e() { return S{0, 0}; }

S mapping(F l, S r) { return S{r.a * l.a + r.size * l.b, r.size}; }

F composition(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }

F id() { return F{1, 0}; }


ll mod = 998244353;
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int aa = 1;
    vector<S> a(n);
    a[0] = aa;
    
    ll sum = aa;
    for (int i = 1; i < n; i++) {
        sum += aa;
        sum %= mod;
        a[i] = S{a, 1};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    lazy_segtree<S, op, e, F, mapping, composition, id> segdef(a);

    for (int i = 0; i < q; i++) {
        int l, r, d; cin >> l >> r >> d;
        ans -= seg.prod(l, r+1).a.val());
        seg.apply(l, r+1, F{1, d});
        cout << ans << endl;
    }
}