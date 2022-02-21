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

int main(){
    ll n; cin >> n;
    vector<vector<ll> > ruiseki(n+1, vector<ll>(n+1, 0));
    REP(i, 0, n){
        REP(l, 0, n){
            cin >> ruiseki[i+1][l+1];
        }
    }
    REP(i, 0, n+1){
        REP(l, 0, n){
            ruiseki[i][l+1] = ruiseki[i][l+1] + ruiseki[i][l];
        }
    }
    REP(l, 0, n+1){
        REP(i, 0, n){
            ruiseki[i+1][l] = ruiseki[i][l] + ruiseki[i+1][l];
        }
    }
    /*REP(i, 0,  n+1){
        REP(l, 0, n+1){
            cout << ruiseki[i][l];
        }
        cout << endl;
    }*/
    vector<ll> maxlis(10000, 0);
    REP(i, 0, n){
        REP(l, 0, n){
            //i and l are now position.
            for(ll j = 1; j + i <= n; j++){
                for(ll k = 1; k + l <= n; k++){
                    ll val = ruiseki[i+j][k+l] + ruiseki[i][l] - ruiseki[i+j][l] - ruiseki[i][k+l];
                    int point = j * k;
                    maxlis[point] = max(val, maxlis[point]);
                }
            }
        }
    }
    /*REP(i, 0, 10){
        cout << maxlis[i] << endl;
    }*/
    int q; cin >> q;

    REP(i, 0, q){
        int a; cin >> a;
        ll ans = 0;
        REP(l, 1, a+1){
            ans = max(ans, maxlis[l]);
        }
        cout << ans << endl;
    }
}