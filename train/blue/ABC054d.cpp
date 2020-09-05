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
    int n, ma, mb; cin >> n >> ma >> mb;
    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(500, vector<int>(500, 1e9)));
    dp[0][0][0] = 0;
    vector<vector<int>> lis(n, vector<int>(3));
    REP(i, 0, n){
        int a, b, c; cin >> a >> b >> c;
        lis[i][0] = a;
        lis[i][1] = b;
        lis[i][2] = c;
    }
    REP(i, 0, n){
        dp[i+1] = dp[i];
        for(int l = 499; l >= 0; l--){
            for(int k = 499; k >= 0; k--){
                if(dp[i][l][k] != 1e9){
                    chmin(dp[i+1][l+lis[i][0]][k+lis[i][1]], dp[i][l][k] + lis[i][2]);
                }
            }
        }
    }
    int ans = 1e9;
    REP(i, 1, 401){
        REP(l, 1, 401){
            if(i * mb == l * ma){
                chmin(ans, dp[n][i][l]);
            }
        }
    }
    if(ans == 1e9){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}