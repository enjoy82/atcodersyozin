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
    ll a, b, n, m; cin >> a >> b >> n >> m;
    if(n + m > a + b){
        cout << "No" << endl;
        return;
    }
    ll cn = n;
    n =  max(n- abs(a-b), 0LL);
    ll dif = cn - n;
    if(n == 0){
        ll k = min(a, b);
        if(k >= m){
            cout << "Yes" << endl;
            return;
        }else{
            cout << "No" << endl;
            return;
        }
    }else{
        a = min(a, b);
        b = min(a, b);
        if(m <= a){
            cout << "Yes" << endl;
            return;
        }
        if(n >= m){
            cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}