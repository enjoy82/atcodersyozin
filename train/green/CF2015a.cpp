#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll n, k, m, r; cin >> n >> k >> m >> r;
    ll mid = k * r;
    vector<ll> lis(n-1);
    REP(i, 0, n-1){
        cin >> lis[i];
    }
    sort(ALL(lis), greater<>());
    ll c = 0;
    REP(i, 0, k-1){
        c += lis[i];
    }
    if(mid-c > m){cout << -1 << endl; return 0;}
    if(n-k > 0){
        ll f = c + lis[k-1];
        if(f >= mid){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << max(mid-c, 0ll) << endl;
}