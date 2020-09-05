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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if(t1*a1 + t2 * a2 == t1 * b1 + t2 * b2){
        cout << "infinity" << endl;
        return 0;
    }
    if(b1 > a1){
        ll x = b1; b1 = a1; a1 = x;
        x = b2; b2 = a2; a2 = x;
    }
    if(t1 * a1 > t1 * b1 && t1*a1 + t2 * a2 <= t1 * b1 + t2 * b2){
        ll dif = t1 * (a1 - b1);
        ll af = t2 * (a2 - b2);
        ll k = abs(dif/(dif + af));
        if(dif %(dif + af) == 0){
            cout << 2*k << endl;
        }else{
            cout << 2*k + 1<< endl;
        }
    }else{
        cout << 0 << endl;
        return 0;
    }
}