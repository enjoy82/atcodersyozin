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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    int n; cin >> n;
    vector<ll> lis0(n), lis1(n);
    REP(i, 0, n){
        scanf("%lld %lld", &lis0[i], &lis1[i]);
    }
    ll mid = max(lis0[0] - lis1[n-1], 0LL);
    REP(i, 0, n-1){
        mid += max(lis0[i+1] -  lis1[i], 0LL);
    }
    ll ans = mid - max(lis0[0] - lis1[n-1], 0LL) + lis0[0];
    REP(i, 0, n-1){
        ans = min(ans, mid - max(lis0[i+1] - lis1[i], 0LL) + lis0[i+1]);
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}