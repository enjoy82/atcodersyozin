#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    int n, m, x, y; cin >> n >> m >> x >> y;
    ll ans = 0;
    REP(i, 0, n){
        string s; cin >> s;
        REP(l, 0, s.size()-1){
            if(s[l] == '.'){
                if(s[l+1] == '.' && y < x*2){
                    s[l] = '*';
                    s[l+1] = '*';
                    ans += y;
                    continue;
                }else{
                    s[l] = '*';
                    ans += x;
                }
            }
        }
        if(s.back() == '.'){
            s.back() = '*';
            ans += x;
        }
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}