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

int main(){
    ll a, b, q; cin >> a >> b >> q;
    vector<ll>slis(a), tlis(b), nslis(a, 0), ntlis(b, 0);
    REP(i, 0, a){cin >> slis[i];}
    REP(i, 0, b){cin >> tlis[i];}
    REP(i, 0, a){
        auto it = lower_bound(ALL(tlis), slis[i]);
        int k = it - tlis.begin();
        ll mi = 1e17;
        if(k - 1 >= 0){
            mi = min(mi, abs(tlis[k-1] - slis[i]));
        }
        if(k < b){
            mi = min(mi, abs(tlis[k] - slis[i]));
        } 
        if(k+1 < b){
            mi = min(mi, abs(tlis[k+1] - slis[i]));
        }
        nslis[i] = mi;
    }
    REP(i, 0, b){
        auto it = lower_bound(ALL(slis), tlis[i]);
        int k = it - slis.begin();
        ll mi = 1e17;
        if(k - 1 >= 0){
            mi = min(mi, abs(slis[k-1] - tlis[i]));
        }
        if(k < a){
            mi = min(mi, abs(slis[k] - tlis[i]));
        } 
        if(k+1 < a){
            mi = min(mi, abs(slis[k+1] - tlis[i]));
        }
        ntlis[i] = mi;
    }
    REP(i, 0, q){
        ll x; cin >> x;
        auto it = lower_bound(ALL(slis), x);
        int k = it - slis.begin();
        ll mi1 = 1e17, mi2 = 1e17;
        if(k - 1 >= 0){
            mi1 = min(mi1, abs(slis[k-1]-x) + nslis[k-1]);
        }
        if(k < a){
            mi1 = min(mi1, abs(slis[k]-x) + nslis[k]);
        } 
        if(k+1 < a){
            mi1 = min(mi1, abs(slis[k+1]-x) + nslis[k+1]);
        }
        auto it1 = lower_bound(ALL(tlis), x);
        int k1 = it1 - tlis.begin();
        if(k1 - 1 >= 0){
            mi2 = min(mi2, abs(tlis[k1-1]-x) + ntlis[k1-1]);
        }
        if(k1 < b){
            mi2 = min(mi2, abs(tlis[k1]-x) + ntlis[k1]);
        } 
        if(k1+1 < b){
            mi2 = min(mi2, abs(tlis[k1+1]-x) + ntlis[k1+1]);
        }
        cout << min(mi1, mi2) << endl;
    }
}