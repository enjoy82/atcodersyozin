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
    ll ans = 0;
    ll mid = (n - k) / k;
    ans += (mid+1) * (mid+1) * (mid+1);
    if(k > n){
        ans = 0;
    }
    if(k%2 == 0){
        mid = (n-k/2) / k;
        if(!((k/2) >n)){
            ans += (mid+1) * (mid+1) * (mid+1);
        }
    }
    cout << ans << endl;
}