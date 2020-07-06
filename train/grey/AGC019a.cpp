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
    ll q, h, s, d, n; cin >> q >> h >> s >> d >> n;
    ll ans = 0;
    ll t = min({q*4, h*2, s});
    if(n % 2 == 1){
        if(t*2 <= d){
            ans = t*n;
        }else{
            ans = t + (d*(n/2));
        }
    }else{
        t *= 2;
        ans = min(t, d) * (n/2);
    }
    cout << ans << endl;
}