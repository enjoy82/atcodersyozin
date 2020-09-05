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

int main(){
    ll n, k; cin >> n >> k;
    ll sum = 0;
    vector<int> plis(n);
    vector<ll> clis(n);
    ll ans = -1 * 1e15;
    REP(i, 0, n){cin >> plis[i]; plis[i]--;}
    REP(i, 0, n){cin >> clis[i]; sum += clis[i];}
    if(sum >= 0){
        sum *= max((k / n)-1, 0LL);
        k -= max((k / n)-1, 0LL) * n;
        REP(i, 0, n){
            ll mid = sum;
            int key = i;
            REP(l, 0, k){
                key = plis[key];
                mid += clis[key];
                //cout << mid << endl;
                ans = max(ans, mid);
            }
        }
    }else{
        REP(i, 0, n){
            ll mid = 0;
            int key = i;
            REP(l, 0, min(n, k)){
                key = plis[key];
                mid += clis[key];
                ans = max(ans, mid);
            }
        }
    }
    cout << ans << endl;
}