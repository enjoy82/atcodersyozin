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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll r, c, k; cin >> r >> c >> k;
    int x = 0, y = 0;
    vector<vector<ll> > lis(r, vector<ll>(c, 0));
    vector<vector<vector<ll> > > dp(r+1, vector<vector<ll> >(c+1, vector<ll>(4, -1)));
    dp[0][0][0] = 0;
    REP(i, 0, k){
        ll r, c, v; cin >> r >> c >> v;
        r--; c--;
        lis[r][c] = v;
    }
    REP(i, 0, r){
        REP(l, 0, c){
            if(lis[i][l] != 0){
                for(int k = 2; k>= 0; k--){
                    chmax(dp[i][l][k+1], dp[i][l][k] + lis[i][l]);
                }
            }
            REP(k, 0, 4){
                chmax(dp[i][l+1][k], dp[i][l][k]);
            }
            dp[i+1][l][0] = max({dp[i+1][l][0], dp[i][l][0], dp[i][l][1], dp[i][l][2], dp[i][l][3]});
        }
    }
    ll ans = 0;
    REP(i, 0, c+1){
        chmax(ans, dp[r][i][0]);
    }
    cout << ans << endl;
}