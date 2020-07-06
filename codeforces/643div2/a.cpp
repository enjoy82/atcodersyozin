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

void solve(){
    ll a, k; cin >> a >> k;
    REP(i, 0, k-1){
        vector<ll> lis;
        string c = to_string(a);
        REP(i, 0, c.size()){
            lis.pb(c[i]-'0');
        }
        sort(ALL(lis));
        if(lis[0] == 0){
            cout << a << endl;
            return;
        }
        a = a + (lis[0] * lis.back());
    }
    cout << a << endl;
}

int main(){
    ll t; cin >> t;
    REP(i, 0, t){solve();}
}