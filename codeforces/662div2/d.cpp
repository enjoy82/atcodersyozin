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
    int n, m; cin >> n >> m;
    vector<string> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    vector<vector<Pii>> dp(n, vector<Pii>(m, Pii(1, 1)));
    vector<vector<Pii>> dp2(n, vector<Pii>(m, Pii(1, 1)));
    ll ans = 0;
    REP(i, 0, n){
        REP(l, 1, m){
            if(lis[i][l-1] == lis[i][l]){
                dp[i][l].first += dp[i][l-1].first;
            }
        }
        for(int l = m-1; l >= 1; l--){
            if(lis[i][l] == lis[i][l-1]){
                dp[i][l-1].second += dp[i][l].second;
            }
        }
    }
    REP(l, 0, m){
        REP(i, 1, n){
            if(lis[i-1][l] == lis[i][l]){
                dp2[i][l].first = min({dp2[i][l].first + dp2[i-1][l].first, dp[i][l].first, dp[i][l].second});
            }
        }
        for(int i = n-1; i >= 1; i--){
            if(lis[i][l] == lis[i-1][l]){
                dp2[i-1][l].second = min({dp2[i][l].second + dp2[i-1][l].second, dp[i-1][l].first, dp[i-1][l].second});
            }
        }
    }
    REP(i, 0, n){
        REP(l, 0, m){
            ans += min(dp2[i][l].first, dp2[i][l].second);
        }
    }
    cout << ans << endl;
}