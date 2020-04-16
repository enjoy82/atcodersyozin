#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb puah_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll a, b, x; cin >> a >> b >> x;
    ll r = 1, l = 1e9;
    while(l-r != 0){
        ll k = (l + r) / 2;
        ll c = a * k + b * to_string(k).length();
        if(c >= x){
            if(l == k){break;}
            l = k;
        }else{
            if(r == k){break;}
            r = k;
        }
        if(r > l){
            ll x = r; r = l; l = x;
        }
    }
    if(a * r + b * to_string(r).length() > x){
        cout << 0 << endl;
        return 0;
    }
    if(a * l + b * to_string(l).length() <= x){
        cout << l << endl;
    }else{
        cout << r << endl;
    }
}