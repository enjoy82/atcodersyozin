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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    ll a, b, c, r; cin >> a >> b >> c >> r;
    if(a > b){
        ll x = b; b = a; a = x;
    }
    if(c-r >= a && c+r <= b){
        cout<< (c-r-a) + (b-(c+r)) << endl;
    }else if(c-r <= b && c-r >= a){
        cout << c-r - a << endl;
    }else if(c+r >= a && c+r <= b){
        cout << b-(c+r) << endl;
    }else if(c-r <= a && c+r >= b){
        cout << 0 << endl;
    }else{
        cout << b-a << endl;
    }
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}