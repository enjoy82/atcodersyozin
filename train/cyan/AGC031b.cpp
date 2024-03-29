#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll mod = 1e9 + 7;

int main(){
    ll n; cin >> n;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    map<int, int> mp;
    vector<int> prev(n, -1);
    REP(i, 0, n){
        if(mp.count(lis[i])){
            prev[i] = mp[lis[i]];
            mp[lis[i]] = i;
        }else{
            mp[lis[i]] = i;
        }
    }
    vector<ll> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    REP(i, 1, n){
        dp[i+1] = dp[i] % mod; //copy prev dp
        if(prev[i] == -1){
            continue;
        }
        if(i-prev[i] == 1){ //exclude
            continue;
        }
        dp[i+1] += dp[prev[i]+1]; //配列一個ずれてること忘れずに
        dp[i+1] %= mod;
    }
    cout << dp[n];
}