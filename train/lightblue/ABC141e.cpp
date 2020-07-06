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
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = n-1; i >= 0; i--){
        for(int l = n-1; l >= 0; l--){
            if(s[i] != s[l]){
                dp[i][l] = 0;
            }else{
                dp[i][l] = dp[i+1][l+1] + 1;
            }
        }
    }
    REP(i, 0, n){
        REP(l, 0, n){
            if(l <= i){
                continue;
            }else{
                chmax(ans, min(dp[i][l], l - i)); //かぶり消す
            }
        }
    }
    cout << ans << endl;
}