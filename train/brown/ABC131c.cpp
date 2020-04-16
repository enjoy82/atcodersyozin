#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll bb = b / c + b / d - b / (lcm(c, d));
    ll aa = (a-1) / c + (a-1) / d - (a-1) / (lcm(c,d));
    cout << b - a + 1 - (bb - aa) << endl;
}