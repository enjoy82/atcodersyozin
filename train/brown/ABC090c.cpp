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
    ll n, m; cin >> n >> m;
    if((n == 1 && m == 2) || (n == 2 && m == 1)){
        cout << 2 << endl;
        return 0;
    }
    if((n == 2 && m == 2) || n == 2 || m == 2 ){
        cout << 0 << endl;
        return 0;
    }
    cout << max(1LL, (n-2)) * max(1LL, (m-2)) << endl;
}