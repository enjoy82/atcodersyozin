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
    ll a, b, c; cin >> a >> b >> c;
    ll A;
    ll aa = a/2, bb = a - a/2;
    A = abs(aa*b*c - bb*b*c);
    aa = b/2, bb = b-b/2;
    A = min(abs(aa*a*c - bb*a*c), A);
    aa = c/2, bb = c-c/2;
    A = min(abs(aa*a*b - bb*a*b), A);
    cout << A << endl;
}