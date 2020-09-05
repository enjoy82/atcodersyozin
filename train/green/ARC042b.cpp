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
    double x, y; cin >> x >> y;
    int n; cin >> n;
    vector<double> xlis(n), ylis(n);
    REP(i, 0, n){cin >> xlis[i] >> ylis[i];}
    double a = ylis[n-1]-ylis[0], b = xlis[0]-xlis[n-1], c = (ylis[0]-ylis[n-1])*xlis[n-1] - (xlis[0]-xlis[n-1]) * ylis[n-1];
    double ans = (abs(a*x + b*y + c) / pow(a*a+b*b, 0.5));
    REP(i, 0, n-1){
        a = ylis[i]-ylis[i+1], b = xlis[i+1]-xlis[i], c = (ylis[i+1]-ylis[i])*xlis[i] - (xlis[i+1]-xlis[i]) * ylis[i];
        chmin(ans, (abs(a*x + b*y + c) / pow(a*a+b*b, 0.5)));
    }
    cout << std::fixed << std::setprecision(15) << ans << endl;
}