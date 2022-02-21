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
    int n, t; cin >> n >> t;
    vector<vector<int>> lis(n, vector<int>(2));
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1];
    }
    sort(ALL(lis), [](auto &x, auto &y){return x[0] < y[0];});
    vector<vector<int> > dp(n+1, vector<int>(t+1, 0));
    REP(i, 0, n){
        dp[i+1] = dp[i];
        chmax(dp[i+1][min(lis[i][0], t)],  dp[i][0] + lis[i][1]);
        REP(l, 1, t){
            if(dp[i][l] != 0){
                dp[i+1][min(l+lis[i][0], t)] = max(dp[i+1][min(l+lis[i][0], t)], dp[i][l] + lis[i][1]);
            }
        }
    }
    int ans = 0;
    REP(i, 0, t+1){
        chmax(ans, dp[n][i]);
    }
    cout << ans << endl;
}