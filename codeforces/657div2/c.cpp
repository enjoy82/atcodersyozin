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
    ll n, m; cin >> n >> m;
    ll ans = 0;
    priority_queue<Pll> pq;
    vector<ll> blis(m), alis(m);
    REP(i, 0, m){
        ll a, b; cin >> a >> b;
        pq.push(Pll(a + b, i));
        blis[i] = b;
        alis[i] = a;
    }
    vector<int> flag(m);
    while(n > 2){
        Pll c = pq.top();
        pq.pop();
        if(c.second >= 0){
            ans += c.first;
            pq.push(Pll(blis[c.second] * 2, -1));
            flag[c.second]++;
            n -= 2;
        }else{
            ans += (c.first / 2) * (n - (n % 2));
            n = n - (n - (n % 2));
        }
    }
    cout << n << endl;
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}