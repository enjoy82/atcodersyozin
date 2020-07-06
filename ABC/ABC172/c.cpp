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
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> alis(1e7), blis(1e7);
    REP(i, 0, n){
        cin >> alis[i];
    }
    REP(i, n, 1e7){
        alis[i] = 1e15;
    }
    REP(i, 0, m){
        cin >> blis[i];
    }
    REP(i, m, 1e7){
        blis[i] = 1e15;
    }
    int aidx = 0, bidx = 0;
    int ans = 0;
    while(1){
        //cout << ans << endl;
        //cout << aidx << bidx << endl << k << endl;
        //cout << alis[aidx]  << " " <<  blis[bidx] << endl;
        if(alis[aidx] < blis[bidx]){
            if(alis[aidx] <= k){
                k -= alis[aidx];
                aidx++;
                ans++;
            }else{
                break;
            }
        }else{
            if(blis[bidx] <= k){
                k -= blis[bidx];
                bidx++;
                ans++;
            }else{
                break;
            }
        }
    }
    cout << ans << endl;
}