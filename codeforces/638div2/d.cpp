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

ll check(vector<ll>lis, int n){
    ll c = 0;
    REP(i, 0, lis.size()){
        c += lis[i];
    }
    if(n == c)
        return 0;
    else
        return c-n;
}

void solve(){
    ll n; cin >> n;
    if(n == 2){
        cout << 1 << endl << 0 << endl;
        return;
    }
    int c = 1, count = -1;
    while(n >= c){
        c *= 2;
        count++;
    }
    n--;
    cout << count << endl;
    vector<ll> lis(count, 0);
    lis[0] = 2;
    REP(i, 1, count){
        lis[i] = 2 * lis[i-1];
    }
    ll t;
    while(t = check(lis, n) != 0){
        for(int l = count-1; l >= 1; l--){
            ll h = lis[l];
            lis[l] = max(lis[l-1], lis[l]-t);
            t -= h - lis[l];
        }
    }
    int ans = 1;
    REP(i, 0, count){
        cout << lis[i] - ans << " ";
        ans = lis[i];
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}