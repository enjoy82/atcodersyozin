#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    REP(i, n){cin >> lis[i];}
    map<ll, ll> mp;
    REP(i, n){
        mp[lis[i]]++;
    }
    ll ans = 0;
    for(auto &x: mp){
        if(x.second > x.first){
            ans += x.second - x.first;
        }else if(x.second < x.first){
            ans += x.second;
        }
    }
    cout << ans << endl;
}