#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        ans = lcm(ans, a);
    }
    cout << ans << endl;
}