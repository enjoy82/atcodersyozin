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

const ll mod = 1e9 + 7;

int check(int a, int b, int c){
    if(a == 1 && c == 0){
        return 2;
    }else if(b == 1 && a == 0){
        return 2;
    }else if(b == 0 && a == 2){
        return 1;
    }else if(c == 0 && b == 1){
        return 2;
    }else if(b == 0 && a == 1){
        return 2;
    }
    return -1;
}

int main(){
    ll n; cin >> n;
    vector<vector<vector<vector<ll> > > > dp(n+1, vector<vector<vector<ll> > >(4, vector<vector<ll> >(4, vector<ll>(4, 0))));
    REP(i, 0, 4){
        REP(l, 0, 4){
            REP(j, 0, 4){
                dp[3][i][l][j] = 1LL;
            }
        }
    }
    dp[3][2][1][0] = 0LL;
    dp[3][1][2][0] = 0LL;
    dp[3][2][0][1] = 0LL;
    REP(i, 4, n+1){
        REP(a, 0, 4){
            REP(b, 0, 4){
                REP(c, 0, 4){
                    REP(d, 0, 4){
                        int ch = check(a, b, c);
                        if(d == 1 && a == 2 && c == 0){
                            //cout << "OK" << ch << endl;
                        }
                        if(ch == d){
                            //cout << d << a << b << endl;
                             continue;
                        }else{
                            dp[i][d][a][b] += dp[i-1][a][b][c];
                            dp[i][d][a][b] %= mod;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    REP(a, 0, 4){
        REP(b, 0, 4){
            REP(c, 0, 4){
                ans += dp[n][a][b][c];
                ans %= mod;
            }
        }
    }
    //cout << dp[n][1][2][0] << endl;
    cout << ans << endl;
}