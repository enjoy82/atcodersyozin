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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> flag(1e6, 0);
    ll g = gcd(n, m);
    for(int i = 0, j = 0; i < n; i += n / g, j += m / g){
        if(s[i] != t[j]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << lcm(n, m) << endl;
}