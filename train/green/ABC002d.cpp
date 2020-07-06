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

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> > check(20, vector<int>(20, 0));
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        check[a][b]++;
        check[b][a]++;
    }
    int ans = 1;
    REP(i, 0, (1 << n)){
        vector<int> lis;
        int c = i, count = 1;
        REP(l, 0, n){
            if((c & 1) == 1){
                lis.pb(count);
            }
            c /= 2;
            count++;
        }
        int k = lis.size();
        int f = 1;
        REP(l, 0, k){
            REP(j, 0, k){
                if(l == j){continue;}
                else{
                    if(check[lis[l]][lis[j]] != 1 && check[lis[j]][lis[l]] != 1){
                        j = k;
                        l = k;
                        f = 0;
                        break;
                    }
                }
            }
        }
        if(f == 1){
            ans = max(ans, k);
        }
    }
    cout << ans << endl;
}