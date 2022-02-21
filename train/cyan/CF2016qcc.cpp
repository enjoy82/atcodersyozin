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

const ll mod = 1e9+7;

int main(){
    int n; cin >> n;
    int f = 1;
    vector<ll> alis(n, 0), blis(n, 0), flag(n, 0), maxlis(n, 0);
    ll k = 0;
    REP(i, 0, n){
        cin >> alis[i];
        if(k < alis[i]){
            flag[i] = 1;
        }
        k = alis[i];
        maxlis[i] = k;
    }
    REP(i, 0, n){
        cin >> blis[i];
    }
    k = 0;
    for(int i = n-1; i >= 0; i--){
        int ff = 0;
        if(k < blis[i]){
            ff = 1;
            k = blis[i];
        }
        if(flag[i] == 1){
            if(ff == 1 && maxlis[i] != k){
                f = 0;
            }else if(ff == 0 && maxlis[i] > blis[i]){
                f = 0;
            }
        }else{
            if(ff == 1 && maxlis[i] < k){
                f = 0;
            }
        }
        if(ff == 1){flag[i] = 1;}
        maxlis[i] = min(k, maxlis[i]);
    }
    if(f == 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    REP(i, 0, n){
        if(flag[i] == 1){continue;}
        else{
            ans = (ans * maxlis[i]) % mod;
        }
    }
    cout << ans << endl;
}