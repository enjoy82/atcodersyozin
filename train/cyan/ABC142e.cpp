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

const ll MOD = 1e9+7;

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % MOD, n / 2);
  else
    return x * Pow(x, n - 1) % MOD;
}


const ll INF = 1e15;

int main(){
    ll n, m; cin >> n >> m;
    ll po = pow(2, n);
    vector<vector<ll> > dp(m+1, vector<ll>(po, INF));
    dp[0][0] = 0;
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        ll k = 0;
        vector<int> ch(n, 0);
        REP(i, 0, b){
            int c; cin >> c;
            ch[c-1] = 1;
        }
        REP(l, 0, po){
            if(dp[i][l] == INF){
                continue;
            }
            ll c = l;
            vector<int> ch1(n, 0);
            REP(k, 0, n){
                if((c & 1) == 1){
                    ch1[k] = 1;
                }
                c /= 2;
            }
            int f = 0;
            REP(k, 0, n){
                if(ch1[k] == 0 && ch[k] == 1){
                    f = 1;
                }
                ch1[k] = max(ch1[k] , ch[k]);
            }
            ll mid = 0;
            ll kk = 1;
            REP(k, 0, n){
                mid += kk * ch1[k];
                kk *= 2;
            }
            //cout << l <<  mid << endl;
            if(f == 1){
                dp[i+1][mid] = min(dp[i][l] + a, dp[i+1][mid]);
            }
        }
        REP(l, 0, po){
            dp[i+1][l] = min(dp[i+1][l], dp[i][l]);
        }
    }
    if(dp[m][po-1] == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << dp[m][po-1] << endl;
}