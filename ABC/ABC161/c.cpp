#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll n, k; cin >> n >> k;
    map<ll, ll> mp;
    n = n % k;
    ll ans = n;
    mp[n]++;
    while(1){
        n = abs(n-k);
        ans = min(n, ans);
        mp[n]++;
        
        if(mp[n] >= 2){
            break;
        }
    }
    cout << ans << endl;
}