#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n; cin >> n;
    vector<ll> lis(n), lis2(n+1, 0);
    REP(i, 0, n){cin >> lis[i];}
    ll ans = (n * (n+1)) / 2;
    map<ll, ll> mp;
    mp[0]++;
    ll mid = 0;
    REP(i, 0, n){
        mid += lis[i];
        lis2[i+1] = mid;
        mp[mid]++;
    }
    REP(i, 0, n){
        ans -= max((mp[lis2[i]] - 1), 0LL);
        mp[lis2[i]]--;
    }
    cout << ans << endl;
}