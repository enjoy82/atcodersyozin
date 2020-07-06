#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

int main(){
    ll n, m; cin >> n >> m;
    ll ans = 0;
    vector<vector<ll> > lis(n, vector<ll>(3));
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1] >> lis[i][2];
    }
    REP(i, 0, (1<<3)){
        vector<ll> ch(n, 0);
        REP(l, 0, n){
            ll tmp = 0;
            int c = i;
            REP(k, 0, 3){
                if(c & 1 == 1){
                    tmp += lis[l][k];
                }else{
                    tmp += (-1 * lis[l][k]);
                }
                c/=2;
            }
            ch[l] = tmp;
        }
        sort(ALL(ch), greater<>());
        ll sum = 0;
        REP(l, 0, m){
            sum += ch[l];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}