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

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> lis(n), ruiseki(n+1), pu;
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 0, n){
        ruiseki[i+1] = ruiseki[i] + lis[i];
    }
    REP(i, 0, n){
        REP(l, i+1, n+1){
            pu.pb(ruiseki[l] - ruiseki[i]);
        }
    }
    n = pu.size();
    for(ll i = 49; i >= 0; i--){
        sort(ALL(pu), greater<>());
        ll c = (1LL << i);
        ll count = 0;
        REP(l, 0, n){
            ll f = 0;
            if((pu[l] & c) > 0){
                f = 1;
            }
            count += f;
        }
        //cout << count << endl;
        if(count >= k){
            pu.erase(pu.begin()+ count, pu.begin()+n);
            n = pu.size();
        }else{
            //cout << "# " << count << endl;
            //cout << c << endl;
            REP(l, 0, n){
                if((pu[l] & c) > 0){
                    //cout << pu[l] << endl;
                    pu[l] -= c;
                }
            }
        }
    }
    sort(ALL(pu),greater<>());
    cout << pu[0] << endl;
}