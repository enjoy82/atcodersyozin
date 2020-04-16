#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll n, m; cin >> n >> m;
    map<ll, ll> mp;
    REP(i, 0, n){
        ll a; cin >> a;
        mp[a]++;
    }
    REP(i, 0, m){
        ll b, c; cin >> b >> c;
        mp[c] += b;
    }
    ll sum = 0;
    for(auto i = mp.rbegin(), e = mp.rend(); i != e && n > 0; ++i){
        //cout << i->first << " " << i->second << endl;
        sum += i->first * min(i->second, n);
        //cout << sum << endl;
        n -= i->second;
    }
    cout << sum << endl;
}