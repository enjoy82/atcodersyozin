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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll mod = 1e9 + 7;

int main(){
    ll a, b; cin >> a >> b;
    ll ans = 1;
    map<ll, ll> mp;
    REP(i, b+1, a+1){
        ll c = i;
        ll l = 2;
        while(l * l <= c) {
            if (c % l == 0) {
                c /= l;
                mp[l]++;
                //cout << l << endl;
            }else{
                l++;
            }
        }
        mp[c]++;
        //cout << c << endl;
    }
    for(auto &x:mp){
        if(x.first == 1){
            continue;
        }else{
            //cout << x.first << " " << x.second << endl;
            ans = (ans * (x.second+1))%mod;
        }
    }
    cout << ans << endl;
}