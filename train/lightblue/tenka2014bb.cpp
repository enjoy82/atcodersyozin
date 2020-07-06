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
    int n; cin >> n;
    const ll mod = 1e9 + 7;
    string spell; cin >> spell;
    vector<string> splis(n);
    REP(i, 0, n){cin >> splis[i];}
    vector<ll> dp(spell.size()+1, 0);
    dp[0] = 1;
    REP(i, 1, spell.size()+1){
        REP(l, 0, n){
            if(i < splis[l].size()){
                continue;
            }
            int f = 1, c = 0;
            REP(j, i-splis[l].size(), i){
                if(spell[j] != splis[l][c]){
                    f = 0;
                    break;
                }
                c++;
            }
            if(f == 1){
                dp[i] = (dp[i] + dp[i-splis[l].size()]) % mod;
            }
        }
    }
    cout << dp[spell.size()] << endl;
}