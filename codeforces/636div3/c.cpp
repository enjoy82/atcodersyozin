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

void solve(){
    ll n; cin >> n;
    ll a; cin >> a;
    int f;
    if(a > 0){
        f = 1;
    }else{
        f = -1;
    }
    ll ans = 0;
    priority_queue<ll> pq, cp;
    pq.push(a);
    REP(i, 0, n-1){
        int b; cin >> b;
        if(f == 1){
            if(b > 0){
                pq.push(b);
            }else{
                ans += pq.top();
                pq = cp;
                pq.push(b);
                f *= -1;
            }
        }else{
            if(b < 0){
                pq.push(b);
            }else{
                ans += pq.top();
                pq = cp;
                pq.push(b);
                f *= -1;
            }
        }
    }
    ans += pq.top();
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}