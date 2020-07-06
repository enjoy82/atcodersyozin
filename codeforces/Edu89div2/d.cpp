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

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}


int main(){
    ll n; cin >> n;
    vector<ll> lis(n), ans1(n), ans2(n);
    REP(i, 0, n){
        ll a;
        scanf("%lld", &a);
        vector<ll> r = divisor(a);
        int key = -1;
        REP(l, 1,  r.size()){
            if(gcd(a, r[l]) == a){
                key = r[l];
            }
        }
        int key2 = -1;
        if(key != -1){
            REP(l, 1, r.size()){
                if(key == r[l]){
                    continue;
                }
                if(r[l] % key != 0){
                    key2 = r[l];
                }
            }
            if(key2 != -1){
                ans1[i] = key;
                ans2[i] = key2;
            }else{
                ans1[i] = -1;
                ans2[i] = -1;
            }
        }else{
            ans1[i] = -1;
            ans2[i] = -1;
        }
    }
    REP(i, 0, n){
        cout << ans1[i] << " ";
    }
    cout << endl;
    REP(i, 0, n){
        cout << ans2[i] << " ";
    }
    cout << endl;
}