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
    vector<ll> lis(3, 0);
    ll k;
    cin >> lis[0] >> lis[1] >> lis[2] >> k;
    ll c, ans = 0;
    c = max(k - lis[0], 0LL);
    ans += abs(k-c);
    k = c;
    c = max(k-lis[1], 0LL);
    k = c;
    c = max(k-lis[2], 0LL);
    ans += (abs(k-c) * -1);
    cout << ans << endl;
}