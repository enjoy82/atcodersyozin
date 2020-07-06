#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}



int main(){
    ll a, b; cin >> a >> b;
    ll i = 2;
    map<ll, ll> mp1, mp2;
    mp1[1] = 1;
    mp2[1] = 1;
    while(a >= i*i){
        if(a % i == 0){
            mp1[i]++;
            a /= i;
        }else{
            i++;
        }
    }
    mp1[a]++;
    i = 2;
    while(b >= i*i){
        if(b % i == 0){
            mp2[i]++;
            b /= i;
        }else{
            i++;
        }
    }
    mp2[b]++;
    ll ans = 0;
    for(auto &x: mp1){
        if(mp2[x.first] != 0){
            ans++;
        }
    }
    cout << ans << endl;
}