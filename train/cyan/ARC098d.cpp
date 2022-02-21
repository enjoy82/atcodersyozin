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

int check(vector<ll> ch){
    REP(i, 0, 20){
        if(ch[i] > 1){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
    }
    lis.pb(0); lis.pb(0);
    int r = 0;
    ll ans = 0;
    vector<ll> bit(20, 0);
    REP(l, 0, n){
        while(check(bit) == 1){
            if(r == n+1){
                break;
            }else{
                ll c = lis[r], c1 = lis[r];
                REP(k, 0, 20){
                    bit[k] += c % 2;
                    c /= 2;
                }
                r++;
            }
        }
        ans += (r-l-1);
        ll c = lis[l];
        REP(k, 0, 20){
            bit[k] -= c % 2;
            c /= 2;
        }
    }
    cout << ans << endl;
}