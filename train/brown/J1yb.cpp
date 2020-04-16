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

const ll mod = 1e9 + 7;

int main(){
    ll n, k; cin >> n >> k;
    ll ans = 0;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 0, n){
        ll mm = lis[i];
        ll count1 = 0, count2 = 0;
        REP(l, i+1, n){
            if(mm > lis[l]){
                count1++;
            }
        }
        REP(l, 0, n){
            if(mm > lis[l]){
                count2++;
            }
        }
        ll mid = (k * k - (k*(k+1))/2) % mod;
        ans = (ans + ((count1*k) + (count2*mid)) % mod) % mod;
    }
    cout << ans << endl;
}