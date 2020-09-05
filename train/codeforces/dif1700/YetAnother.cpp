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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(){
    int n; cin >> n;
    ll hmax = 0, amax = 0;
    vector<ll> alis(n, 0), days(n, 0);
    REP(i, 0, n){cin >> alis[i]; chmax(amax, alis[i]);} 
    int m; cin >> m;
    vector<vector<ll> > hlis(m, vector<ll>(2,0));
    REP(i, 0, m){
        cin >> hlis[i][0] >> hlis[i][1];
        chmax(days[hlis[i][1] - 1], hlis[i][0]);
        chmax(hmax, hlis[i][0]);
    } 
    if(hmax < amax){
        cout << -1 << endl;
        return;
    }
    for(int i = n-2; i >= 0; i--){
        chmax(days[i], days[i+1]);
    }
    ll day = 0, cur = -1, cons = -1, ans = 0;
    while(day < n){
        chmax(cur, alis[day]);
        cons++;
        if(days[cons] < cur){
            ans++;
            cons = 0;
            cur = alis[day];
        }
        day++;
    }
    ans++;
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}