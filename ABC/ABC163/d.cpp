#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll mod = 1e9 + 7;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> lis1(n+1, 0), lis2(n+1, 0);
    lis1[0] = n;
    REP(i, 1, n+1){
        lis1[i] = lis1[i-1] + (n-i);
        lis2[i] = lis2[i-1] + i;
    }
    ll ans = 0;
    REP(i, k-1, n+1){
        ans = (ans + lis1[i] - (lis2[i]-1)) % mod;
    }
    cout << ans << endl;
}