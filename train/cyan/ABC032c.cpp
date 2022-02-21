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

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> lis(n);
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 0, n){
        if(lis[i] == 0){
            cout << n << endl;
            return 0;
        }
    }
    REP(i, 0, n){
        if(lis[i] <= k){
            break;
        }
        cout << 0 << endl;
        return 0;
    }
    ll mid = lis[0];
    ll ans = 0;
    ll l = 0, r = 0;
    while(r < n && l < n){
        if(mid <= k){
            ans = max(ans, r-l+1LL);
            r++;
            mid *= lis[r];
        }else{
            mid = max(mid/lis[l], 1LL);
            l++;
            if(l > r){
                l++;
                r+=2;
            }
        }
    }
    cout << ans << endl;
}