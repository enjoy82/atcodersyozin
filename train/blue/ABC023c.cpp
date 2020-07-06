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
    ll h, w, k; cin >> h >> w >> k;
    ll n; cin >> n;
    vector<Pll> query(n);
    vector<ll> row(w, 0), column(h, 0);
    REP(i, 0, n){
        ll a, b; cin >> a >> b;
        a--; b--;
        query[i] = {a, b};
        column[a]++;
        row[b]++;
    }
    map<ll, ll> mprow, mpcol;
    REP(i, 0, h){
        mpcol[column[i]]++;
    }
    REP(i, 0, w){
        mprow[row[i]]++;
    }
    ll ans = 0;
    for(auto &x: mpcol){
        ans += x.second * mprow[k-x.first];
    }
    REP(i, 0, n){
        ll x = query[i].first, y = query[i].second;
        if(column[x] + row[y] == k){
            ans--;
        }else if(column[x] + row[y] == k+1){
            ans++;
        }
    }
    cout << ans << endl;
}