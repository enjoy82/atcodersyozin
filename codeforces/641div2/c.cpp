#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;


using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
 
#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
 
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
 
char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
 
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
 
int main(){
    ll n; cin >> n;
    vector<ll> lis(n);
    vector<ll> lclis(3e5+10, 0), flag(3e5+10, 0);
    REP(i, 0, n){cin >> lis[i];}
    ll gc = lis[0];
    REP(i, 0, n-1){
        gc = gcd(lis[i+1], gc);
    }
    if(n == 2){
        cout << lcm(lis[0], lis[1]) << endl;
        return 0;
    }
    REP(i, 0, n){
        lis[i] = lis[i] / gc;
    }
    REP(i, 0, n){
        vector<ll> r = divisor(lis[i]);
        REP(l, 0, r.size()){
            lclis[r[l]]++;
        }
    }
    ll ans = gc;
    for(ll i = 2; i < 3e5; i++){
        if(flag[i] == 0 && lclis[i] >= n-1){
            ll l = i;
            while(l < 3e5 && lclis[l] >= n-1){
                flag[l]++;
                l *= i;
                if(l < 3e5){flag[l]++;}
            }
            l /= i;
            ans *= l;
            for(ll k = i; k < 3e5; k+=i){
                flag[k]++;
            }
        }
    } 
    cout << ans << endl;
}