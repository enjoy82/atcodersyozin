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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> alp(26, 0), alp1(26, 0);
    REP(i, 0, s.size()){
        alp[s[i] - 'A']++;
    }
    REP(i, 0, t.size()){
        alp1[t[i] - 'A']++;
    }
    int ans = 0;
    REP(i, 0, 26){
        if(alp[i] != 0){
            if(alp1[i] == 0){
                cout << -1 << endl;
                return 0;
            }else{
                if(alp[i] % alp1[i] == 0){
                    ans = max(ans, alp[i] / alp1[i]);
                }else{
                    ans = max(ans, (alp[i] / alp1[i]) + 1);
                }
            }
        }else{
            continue;
        }
    }
    cout << ans << endl;
}