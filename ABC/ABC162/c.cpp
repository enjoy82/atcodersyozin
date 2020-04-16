#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int k; cin >> k;
    ll ans = 0;
    REP(a, 1, k+1){
        REP(b, 1, k+1){
            REP(c, 1, k+1){
                ans += gcd(gcd(a, b), c);
            }
        }
    }
    cout << ans << endl;
}