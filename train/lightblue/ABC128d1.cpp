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
    int n, k; cin >> n >> k;
    vector<ll> lis(n), rcount(k+1, -1*1e10), lcount(k+1, -1*1e10);
    int size = lis.size();
    rcount[0] = 0, lcount[0] = 0;
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 1, k+1){ //操作回数
        REP(l, 0, i/2+1){ //離す個数
            vector<ll> mid;
            REP(k, 0, min(i-l, )){
                mid.pb(lis[k]);
            }
            sort(ALL(mid), greater<>());
            ll sum = 0;
            REP(k, 0, i-2*l){
                sum += mid[k];
            }
            lcount[i] = max(lcount[i], sum);
        }
    }
    int size = lis.size();
    REP(i, 1, k+1){ //操作回数
        REP(l, 0, i/2+1){ //離す個数
            vector<ll> mid;
            REP(k, 0, i-l){
                mid.pb(lis[size-1-k]);
            }
            sort(ALL(mid), greater<>());
            ll sum = 0;
            REP(k, 0, i-2*l){
                sum += mid[k];
            }
            rcount[i] = max(rcount[i], sum);
        }
    }
    ll ans = -1 * 1e10;
    REP(i, 0, k+1){
        REP(l, 0, k+1-i){
            ans = max(lcount[i] + rcount[l], ans);
        }
    }
    cout << ans << endl;
}  
