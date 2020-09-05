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

void solve(){
    ll l, r, m; cin >> l >> r >> m;
    ll fa, n, dif = 1e9;
    REP(a, l, r+1){
        ll d = m - (m/a) * a;
        ll d1 = m - ((m/a)+1) * a;
        if(m / a == 0){
            if(abs(d1) < abs(dif)){
                n = (m/a) + 1;
                fa = a;
                dif = d1;
            }
        }
        else{
            if(abs(d) <= abs(d1) && abs(d) < abs(dif)){
                n = m/a;
                fa = a;
                dif = d;
            }else if(abs(d) > abs(d1) && abs(d1) < abs(dif)){
                n = (m/a) + 1;
                fa = a;
                dif = d1;
            }
        }
    }
    ll b = l, c = l;
    if(dif < 0){
        c += abs(dif);
    }else{
        b += abs(dif);
    }
    cout << fa << " " << b << " " << c << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}