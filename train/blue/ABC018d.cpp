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
    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;
    vector<vector<Pii>> have(n);
    REP(i, 0, r){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        have[a].pb(Pii(b, c));
    }
    int ans = 0;
    REP(i, 0, (1 << n)){
        int ci = i, count = 0;
        vector<int> men(m, 0);
        REP(l, 0, n){
            if((ci & 1) == 1){
                count++;
                REP(k, 0, have[l].size()){
                    men[have[l][k].first] += have[l][k].second;
                }
            }
            ci = ci >> 1;
        }
        if(count != p){
            continue;
        }
        sort(ALL(men), greater<>());
        int mid = 0;
        REP(l, 0, q){
            mid += men[l];
        }
        chmax(ans, mid);
    }
    cout << ans << endl;
}