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
    ll n, m; cin >> n >> m;
    vector<ll> num(n, 0);
    cin >> num[n-1];
    cout << 1 << endl;
    REP(i, 0, m-1){
        ll a; cin >> a;
        auto it = lower_bound(ALL(num), a);
        int k = it - num.begin();
        if(k == 0){
            cout << -1 << endl;
            continue;
        }
        num[k-1] = a;
        cout << n-(k-1) << endl;
    }
}