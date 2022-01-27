#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<vector<ll>> det = {{32, 29, 42}, {25, 31, 18}, {11, 19, 23}};

inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

ll extGcd(ll X, ll Y, ll &p, ll &q) {  
    if (Y == 0) { p = 1; q = 0; return X; }  
    ll d = extGcd(Y, X%Y, q, p);  
    q -= X/Y * p;  
    return d;
}


ll get_det_by_mod(vector<vector<ll>> array, ll mod){
    return (((det[0][0] * det[1][1] * det[2][2]) % mod) + ((det[0][1] * det[1][2] * det[2][0]) % mod) + ((det[0][2] * det[1][0] * det[2][1]) % mod) \
     - ((det[0][2] * det[1][1] * det[2][0]) % mod) - ((det[0][1] * det[1][0] * det[2][2]) % mod) - ((det[0][0] * det[1][2] * det[2][1]) % mod
     ) + (3*mod)) % mod;
}

ll get_det(vector<vector<ll>> array){
    return (det[0][0] * det[1][1] * det[2][2]) + (det[0][1] * det[1][2] * det[2][0]) + (det[0][2] * det[1][0] * det[2][1]) \
     - (det[0][2] * det[1][1] * det[2][0]) - (det[0][1] * det[1][0] * det[2][2]) - (det[0][0] * det[1][2] * det[2][1]);
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


pair<long long, long long> ChineseRem_array(const vector<long long> &b, const vector<long long> &m) {
  long long r = 0, M = 1;
  for (int i = 0; i < (int)b.size(); ++i) {
    long long p, q;
    pair<ll, ll> res = ChineseRem(r, M, b[i], m[i]);
    r = res.first;
    M = res.second;
  }
  return make_pair(r, M);
}

int main(){
    ll ans = get_det(det);
    ll ans_mod19 = get_det_by_mod(det, 19);
    ll ans_mod23 = get_det_by_mod(det, 23);
    ll ans_mod31 = get_det_by_mod(det, 31);
    vector<long long> b = {ans_mod19, ans_mod23, ans_mod31};
    vector<long long> m = {19, 23, 31};
    cout << "currect det : " << ans << endl << "det mod 19 : " << ans_mod19 << endl << "det mod 23 : " << ans_mod23 << endl << "det mod 31 : " << ans_mod31 << endl;
    cout << "det by ChineseRem " << ChineseRem_array(b, m).first << endl;
}