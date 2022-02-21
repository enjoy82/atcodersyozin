#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll n, g; cin >> n >> g;
    vector<vector<ll> > dp(n+1, vector<ll>(2e4, 0));
    REP(i, 0, n){
        int p, c; cin >> p >> c;
        vector<ll> cpi = dp[i];
        vector<ll> lis = cpi;
        REP(l, 0, p){
            REP(k, 0, 1e4 + 500){
                lis[k+l] = max(cpi[k+l], cpi[k]+l*100*(i+1));
            }
        }
        REP(k, 0, 1e4 + 500){
            lis[k+p] = max(cpi[k+p], cpi[k]+p*100*(i+1)+c);
        }
        dp[i+1] = lis;
    }
    REP(i, 0, 2e4){
        if(dp[n][i] >= g){
            cout << i << endl;
            return 0;
        }
    }
}