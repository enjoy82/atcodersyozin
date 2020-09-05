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

int LCSubsequence(string s1, string s2){
    int l1 = s1.size(), l2 = s2.size();
    vector<vector<int> > dp(l2+1, vector<int>(l1+1, 0));
    REP(i, 1, l2+1){
        REP(j, 1, l1+1){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s1[j-1] == s2[i-1]){
                chmax(dp[i][j], dp[i-1][j-1]+1);
            }
        }
    }
    return dp[l2][l1];
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    REP(i, 0, n){
        string s1 = s.substr(0, i), s2 = s.substr(i, n-i);
        chmax(ans, LCSubsequence(s1, s2));
    }
    cout << n - ans*2 << endl;
}