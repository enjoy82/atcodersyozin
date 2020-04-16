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
    int n; cin >> n;
    vector<vector<ll> > lis(n, vector<ll>(2, 0));
    REP(i, 0, n){cin >> lis[i][0]; lis[i][1] = i + 1;}
    sort(lis.begin(), lis.end(), [](auto &x, auto &y){return x[0] > y[0];});
    REP(i, 0, n){cout << lis[i][1] << endl;}
}