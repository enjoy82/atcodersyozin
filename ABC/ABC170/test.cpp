#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
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
    ll n, q; cin >> n >> q;
    vector<multiset<ll>> c(3e5+100);
    map<ll, ll> mppos, mpval;
    multiset<ll> ansset;
    REP(i, 0, n){
        ll a, b; cin >> a >> b;
        mppos[i+1] = b;
        mpval[i+1] = a;
        c[b].insert(a);
    }
    REP(i, 1, 3e5+100){
        if(c[i].size() > 0){
            ansset.insert(*c[i].rbegin());
            //cout << i << *c[i].rbegin() << endl;
        }
    }
    REP(i, 0, q){
        ll x, y; cin >> x >> y;
        ll val = mpval[x], pos = mppos[x];
        ansset.erase(*c[pos].rbegin());
        c[pos].erase(c[pos].find(val));
        if(!c[pos].empty()){
            ansset.insert(*c[pos].rbegin());
        }
        if(!c[y].empty()){
            ansset.erase(*c[y].rbegin());
        }
        c[y].insert(val);
        ansset.insert(*c[y].rbegin());
        mppos[x] = y;
        cout << *ansset.begin() << endl;
    }
}