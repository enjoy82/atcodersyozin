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
    int n; cin >> n;
    vector<ll> lis(n);
    ll ans1 = 0, ans2 = 0;
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 0, n){
        ans1 += lis[i];
    }
    cout << ans1 << endl;
    sort(ALL(lis), greater<>());
    ll k = lis[0], c = 0;
    REP(i, 1, n){
        c += lis[i];
    }
    if(k < c){
        cout << 0 << endl;
    }else{
        cout << k - c << endl;
    }
}