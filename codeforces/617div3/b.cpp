#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    ll c; cin >> c;
    ll ans = 0;
    while(c != 0){
        double buy = pow(10, (to_string(c).size()-1));
        //cout << c << endl;
        //cout << buy << endl << endl; 
        c = c - buy + (buy / 10);
        ans += buy;
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}