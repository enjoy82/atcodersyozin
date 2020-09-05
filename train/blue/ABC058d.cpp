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

int main(){
    int n, m; cin >> n >> m;
    ll xf, yf; cin >> xf;
    vector<ll> xlis(n-1), ylis(m-1);
    REP(i, 0, n-1){
        ll a; cin >> a;
        xlis[i] = a - xf;
        xlis[i] %= mod;
        xf = a;
    }
    cin >> yf;
    REP(i, 0, m-1){
        ll a; cin >> a;
        ylis[i] = a - yf;
        ylis[i] %= mod;
        yf = a;
    }
    ll xsum = 0, ysum = 0;
    REP(i, 0, n-1){
        xlis[i] = xlis[i] * (i+1) * (n-1-i);
        xsum += xlis[i];
        xsum %= mod;
    }
    REP(i, 0, m-1){
        ylis[i] = ylis[i] * (i+1) * (m-1-i);
        ysum += ylis[i];
        ysum %= mod;
    }
    cout << (ysum * xsum) % mod << endl;
}