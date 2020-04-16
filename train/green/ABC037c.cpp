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
    int n, k; cin >> n >> k;
    vector<ll> lis(n);
    vector<ll> ruiseki(n+1, 0);
    ll mid = 0;
    REP(i, 0, n){
        cin >> lis[i];
        mid += lis[i];
        ruiseki[i+1] = mid;
    }
    ll ans = 0;
    REP(i, k, n+1){
        ans += (ruiseki[i] - ruiseki[i-k]);
    }
    cout << ans << endl;
}