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
    ll high = 1e10, low = 1;
    vector<ll> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
    }
    sort(ALL(lis), greater<>());
    if(k == 0){
        cout << lis[0] << endl;
        return 0;
    }
    while(high - low > 1){
        ll ck = k;
        ll mid = (high + low) / 2;
        REP(i, 0, n){
            if(lis[i] <= mid){
                continue;
            }else{
                ll c = lis[i] / mid;
                ck -= c;
            }
        }
        //cout  << mid  << " " << ck << endl;
        if(ck >= 0 || ck == k){
            high = mid;
        }else{
            low = mid;
        }
    }
    ll ck = k;
    ll mid = low;
    REP(i, 0, n){
        if(lis[i] <= mid){
            continue;
        }else{
            ll c = lis[i] / mid;
            ck -= c;
        }
    }
    if(ck >= 0 || ck == k){
        cout << low << endl;
        return 0;
    }
    cout << high << endl;
}