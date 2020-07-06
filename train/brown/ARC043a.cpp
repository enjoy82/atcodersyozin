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
    int n, a, b; cin >> n >> a >> b;
    vector<ll> lis(n);
    ll sum = 0;
    REP(i, 0, n){cin >> lis[i]; sum += lis[i];}
    sort(ALL(lis));
    ll ma = lis.back(), mi = lis[0];
    ll dif = ma - mi;
    if(dif == 0 && b != 0){
        cout << -1 << endl;
        return 0;
    }
    ld p = (b/(dif*1.0));
    ld q = (a*1.0) - p*(sum*1.0/n);
    cout << std::fixed << std::setprecision(15) << p << " ";
    cout << std::fixed << std::setprecision(15) << q << endl;
}