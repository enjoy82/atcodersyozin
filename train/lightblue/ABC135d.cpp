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

int main(){
    vector<ll> lis(1e6, 0);
    lis[0] = 1;
    REP(i, 1, 1e6){
        lis[i] = (lis[i-1] * 10) % 13;
    }
    string s; cin >> s;
    reverse(ALL(s));
    vector<vector<ll> > dp(s.size()+1, vector<ll>(13, 0));
    dp[0][0] = 1;
    REP(i, 0, s.size()){
        int key = lis[i];
        if(s[i] != '?'){
            int to = (key * (s[i]-'0')) % 13;
            REP(l, 0, 13){
                dp[i+1][(l+to)%13] = (dp[i+1][(l+to)%13] + dp[i][l])%mod;
            }
        }else{
            REP(l, 0, 10){
                int to = (key * l)%13;
                REP(k, 0, 13){
                    dp[i+1][(k+to)%13] = (dp[i+1][(k+to)%13] + dp[i][k])%mod;
                }
            }
        }
    }
    cout << dp[s.size()][5] % mod << endl;
}