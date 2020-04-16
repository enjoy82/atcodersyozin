#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

const ll mod = 1e9 + 7;

ll RepeatSquaring(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2);
        return t*t % mod;
    }
    return ((N * RepeatSquaring(N, P-1)) % mod);
}

int main(){
    ll n, k; cin >> n >> k;
    ll ans = 0;
    vector<int> es(k+1, 0);
    REP(i, 2, k+1){
        if(es[i] == -1){
            continue;
        }
        for(int l = i+i; l < k+1; l += i){
            es[l] = -1;
        }
        ll mid = (i * RepeatSquaring(k/i, n) ) % mod;
        ans = (ans + mid) % mod;
        cout << ans << endl;
    }
    int count = 0;
    REP(i, 1, k+1){
        if(es[i] == 0){
            count++;
        }
    }
    ans = ans + RepeatSquaring(count, n) - (count-1) % mod;
    cout << ans << endl;
}