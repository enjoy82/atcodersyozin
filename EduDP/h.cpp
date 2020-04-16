#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll dx[2] = {1, 0};
ll dy[2] = {0, 1};

const ll mod = 1e9+7;

int main(){
    int h, w; cin >> h >> w;
    vector<vector<ll> > dp(h, vector<ll>(w, 0));
    dp[0][0] = 1LL;
    vector<string> lis(h);
    REP(i, 0, h){cin >> lis[i];}
    REP(i, 0, h){
        REP(l, 0, w){
            REP(k, 0, 2){
                int nx = i+dx[k], ny = l+dy[k];
                if(nx >= 0 && ny >= 0 && nx < h && ny < w && lis[nx][ny] == '.'){
                    dp[nx][ny] = (dp[nx][ny] + dp[i][l]) % mod;
                }
            }
        }
    }
    cout << dp[h-1][w-1];
}