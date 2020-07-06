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

const ll mod = 1e9 + 7;

int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll> > adp(m+1, vector<ll>(n+1, 0));
    vector<vector<ll> > bdp(m+1, vector<ll>(n+1, 0));
    adp[0][n] = 1;
    bdp[0][0] = 1;
    REP(i, 0, m){
        REP(l, 1, n+1){
            REP(j, l, n+1){
                adp[i+1][l] += adp[i][j];
                adp[i+1][l] %= mod;
            }
        }
    }
    REP(i, 0, m){
        REP(l, 1, n+1){
            REP(j, 0, l+1){
                bdp[i+1][l] += bdp[i][j];
                bdp[i+1][l] %= mod;
            }
        }
    }
    ll ans = 0;
    REP(i, 1, n+1){ //adp
        REP(l, 1, i+1){ //bdp
            ans = (ans + (adp[m][i] * bdp[m][l])%mod)%mod;
        }
    }
    cout << ans << endl;
}