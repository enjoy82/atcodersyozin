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

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int check(ll n, ll k){
    while(n >= k){
        if(n % k == 0){
            n = n / k;
        }else{
            n = n % k;
        }
    }
    if(n == 1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    ll n; cin >> n;
    ll ans = 0;
    vector<ll> lis1 = divisor(n);
    REP(i, 1, lis1.size()){
        if(check(n, lis1[i])){
            ans++;
        }
    }
    vector<ll> lis2 = divisor(n-1);
    REP(i, 1, lis2.size()){
        if(check(n, lis2[i])){
            ans++;
        }
    }
    cout << ans << endl;
}