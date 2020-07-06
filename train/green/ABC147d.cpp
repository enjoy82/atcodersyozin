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

const ll mod = 1e9+7;

int main(){
    int n; cin >> n;
    vector<ll> lis(n), lis1(n);
    REP(i, 0, n){cin >> lis[i];}
    ll ans = 0;
    REP(i, 0, 60){
        ll c0 = 0, c1 = 0;
        REP(l, 0, n){
            if((lis[l] >> i) & 1) c1++;
            else c0++;
        }
        ll mid = (((1LL << i) % mod)* ((c0 * c1) % mod)) % mod;
        ans = (ans + mid) % mod; 
    }
    cout << ans << endl;
}