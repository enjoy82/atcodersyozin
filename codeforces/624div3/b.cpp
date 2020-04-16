#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> alis(n), plis(200, 0), lis;
    REP(i, 0, n){cin >> alis[i];}
    REP(i, 0, m){int p; cin >> p; plis[p]++;}
    int ma = alis[0], mi = alis[0];
    REP(i, 1, n){
        if(plis[i] == 1){
            ma = max(ma, alis[i]);
            mi = min(mi, alis[i]);
        }else{
            if(ma == mi){
                lis.pb(ma);
            }else{
                lis.pb(mi);
                lis.pb(ma);
            }
            ma = alis[i];
            mi = alis[i];
        }
    }
    lis.pb(mi);
    lis.pb(ma);
    int k = lis[0];
    REP(i, 1, lis.size()){
        if(k > lis[i]){
            cout << "NO" << endl;
            return;
        }
        k = lis[i];
    }
    cout << "YES" << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){
        solve();
    }
}