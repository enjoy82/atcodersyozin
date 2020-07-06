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
ll ans = 0;
ll n, m;
vector<vector<ll> > dp;
vector<vector<ll> > lis;

ll solve(int x, int y){
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    ll key = 0;
    REP(i, 0, 4){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && lis[x][y] < lis[nx][ny]){
            key += solve(nx, ny);
        }
    }
    dp[x][y] = (key+1)%mod;
    return (key + 1)%mod;
}

int main(){
    cin >> n >> m;
    lis = vector<vector<ll> >(n, vector<ll>(m));
    dp = vector<vector<ll> >(n, vector<ll>(m, 0));
    REP(i, 0, n){
        REP(l, 0, m){
            cin >> lis[i][l];
        }
    }
    REP(i, 0, n){
        REP(l, 0, m){
            ans = (ans + solve(i, l))%mod;
        }
    }
    cout << ans << endl;
}