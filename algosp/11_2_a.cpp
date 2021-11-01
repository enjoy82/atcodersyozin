#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<vector<ll>> det = {{1801, 840, 2889}, {465, 213, 741}, {225, 105, 361}};
const ll mod3 = 3;
const ll mod5 = 5;

inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

ll extGcd(ll X, ll Y, ll &p, ll &q) {  
    if (Y == 0) { p = 1; q = 0; return X; }  
    ll d = extGcd(Y, X%Y, q, p);  
    q -= X/Y * p;  
    return d;  
}

// 中国剰余定理
pair<ll, ll> ChineseRem(ll b1, ll m1, ll b2, ll m2) {
  ll p, q;
  ll d = extGcd(m1, m2, p, q);
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  ll m = m1 * (m2/d);
  ll tmp = (b2 - b1) / d * p % (m2/d);
  ll r = ((b1 + m1 * tmp) % m + m) % m;
  return make_pair(r, m);
}

int main(){
    ll ans_by_mod3 = (((det[0][0] * det[1][1] * det[2][2]) % mod3) + ((det[0][1] * det[1][2] * det[2][0]) % mod3) + ((det[0][2] * det[1][0] * det[2][1]) % mod3) \
     - ((det[0][2] * det[1][1] * det[2][0]) % mod3) - ((det[0][1] * det[1][0] * det[2][2]) % mod3) - ((det[0][0] * det[1][2] * det[2][1]) % mod3) + (3*mod3)) % mod3;
    ll ans_by_mod5 = (((det[0][0] * det[1][1] * det[2][2]) % mod5) + ((det[0][1] * det[1][2] * det[2][0]) % mod5) + ((det[0][2] * det[1][0] * det[2][1]) % mod5) \
     - ((det[0][2] * det[1][1] * det[2][0]) % mod5) - ((det[0][1] * det[1][0] * det[2][2]) % mod5) - ((det[0][0] * det[1][2] * det[2][1]) % mod5) + (3*mod5)) % mod5;
    ll ans = (det[0][0] * det[1][1] * det[2][2]) + (det[0][1] * det[1][2] * det[2][0]) + (det[0][2] * det[1][0] * det[2][1]) \
     - (det[0][2] * det[1][1] * det[2][0]) - (det[0][1] * det[1][0] * det[2][2]) - (det[0][0] * det[1][2] * det[2][1]);
    cout << "currect det : " << (ans + 15) % 15 << endl << "det by mod3 : " << ans_by_mod3 << endl << "det by mod5 : " << ans_by_mod5 << endl;
    pair<long long, long long> cans = ChineseRem(ans_by_mod3, 3, ans_by_mod5, 5);
    cout << "chinese rem : " << cans.first << endl;
}