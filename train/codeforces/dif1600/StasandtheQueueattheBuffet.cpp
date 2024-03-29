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

int main(){
    int n; cin >> n;
    vector<vector<ll> > lis(n, vector<ll>(3, 0));
    REP(i, 0, n){
        ll a, b; cin >> a >> b;
        lis[i][0] = a - b;
        lis[i][1] = a;
        lis[i][2] = b;
    }
    sort(ALL(lis), greater<>());
    ll ans = 0;
    REP(i, 0, n){
        ans += lis[i][1]*(i) + lis[i][2]*(n-1-i);
    }
    cout << ans << endl;
}