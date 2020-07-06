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



int main(){
    ll a, r, n; cin >> a >> r >> n;
    if(r == 1){
        if(a > 1e9){
            cout << "large" << endl;
        }else{
            cout << a << endl;
        }
        return 0;
    }
    ll k = a;
    REP(i, 0, n-1){
        k = k * r;
        if(k > 1e9){
            cout << "large" << endl;
            return 0;
        }
    }
    cout << k << endl;
}