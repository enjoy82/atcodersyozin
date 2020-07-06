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
    vector<ll> lis(n+1), ruiseki(n+1);
    REP(i, 0, n+1){cin >> lis[i];}
    ruiseki[n] = lis[n];
    for(int i = n-1; i >= 0; i--){
        ruiseki[i] = ruiseki[i+1] + lis[i];
    }
    if(n == 0){
        if(lis[0] == 1){
            cout << 1 << endl;
            return 0;
        }else if(lis[0] == 0){
            cout << 0 << endl;
            return 0;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    vector<ll> tree(n+1);
    if(lis[0] == 1){
        cout << -1 << endl;
        return 0;
    }
    tree[0] = 1;
    ll next = tree[0];
    for(int i = 1; i < n+1; i++){
        tree[i] = min(ruiseki[i], next*2);
        next = tree[i] - lis[i];
        if(next < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    REP(i, 0, n+1){
        ans += tree[i];
    }
    cout << ans << endl;
}