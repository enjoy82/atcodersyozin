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
    int n, h, l, r; cin >> n >> h >> l >> r;
    vector<int> lis(n);
    cin >> lis[0];
    vector<vector<int> > dp(n+2, vector<int>(n+2, -1));
    REP(i, 1, n){
        int a; cin >> a;
        lis[i] = lis[i-1] + a;
    }
    dp[0][0] = 0;
    REP(i, 0, n){
        REP(j, 0, n+2){
            if(dp[i][j] == -1){continue;}
            REP(k, 0, 2){
                int next = (lis[i] + h - (j + k)) % h;
                int f = 0;
                if(next >= l && next <= r){f = 1;}
                dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j]+f);
            }
        }
    }
    int ans = 0;
    REP(i, 0, n+2){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}