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

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(2, 0));
    dp[0][0] = s[0]-'0'-1;
    dp[0][1] = s[0]-'0';
    REP(i, 1, n){
        if(s[i] != '0'){
            dp[i][0] = max(dp[i-1][0] + 9 , dp[i-1][1] + (s[i]-'0')-1);
        }else{
            dp[i][0] = dp[i-1][0] + 9;
        }
        dp[i][1] = dp[i-1][1] + (s[i]-'0');
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
}