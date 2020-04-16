#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll n, h, a, b, c, d, e; cin >> n >> h >> a >> b >> c >> d >> e;
    ll ans = 1e18;
    REP(x, 0, n+1){
        ll y = ((e*(n-x)-(h+b*x))*1.0) / ((d+e)*1.0) +1;
        //cout << x << y << endl;
        y = max(0ll, y);
        if((n-x-y >= 0) && b*x+d*y+h > (n-x-y)*e)
            ans = min(ans, (x*a+y*c));
    }
    cout << ans << endl;
}
