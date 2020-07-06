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
    ll n, m, x; cin >> n >> m >> x;
    vector<ll> lis(n);
    vector<vector<ll> > alis(n, vector<ll>(m, 0));
    ll ans = 2e11;
    REP(i, 0, n){
        cin >> lis[i];
        REP(l, 0, m){
            cin >> alis[i][l];
        }
    }
    REP(i, 0, (1 << n)){
        vector<ll> mid(m, 0);
        ll sum = 0;
        ll c = i;
        REP(l, 0, n){
            if(c & 1 == 1){
                sum += lis[l];
                REP(j, 0, m){
                    mid[j] += alis[l][j];
                }
            }
           c = (c >> 1);
        }
        int f = 1;
        REP(l, 0, m){
            if(x > mid[l]){
                f = 0;
            }
        }
        if(f == 0){
            continue;
        }else{
            ans = min(ans, sum);
        }
    }
    if(ans == 2e11){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}