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

int solve(string s, string a, string b){
    int count = 0;
    REP(i, 0, s.size()){
        if(i+1 < s.size() && s[i] == a[0] && s[i+1] == a[1]){
            i++;
        }else if(i+1 < s.size() &&s[i] == b[0] && s[i+1] == b[1]){
            i++;
        }
        count++;
    }
    return count;
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 1e9;
    string lis[4] = {"A", "B", "X", "Y"};
    REP(a, 0, 4){
        REP(b, 0, 4){
            REP(c, 0, 4){
                REP(d, 0, 4){
                    string x = lis[a] + lis[b], y = lis[c] + lis[d];
                    if(x == y){continue;}
                    ans = min(ans,solve(s, x, y));

                }
            }
        }
    }
    cout << ans << endl;
}