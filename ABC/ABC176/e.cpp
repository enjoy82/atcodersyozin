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
    ll h, w, m; cin >> h >> w >> m;
    vector<Pll> H(h, Pll(0, 0)), W(w, Pll(0, 0));
    map<Pll, ll> mp;
    REP(i, 0, h){
        H[i].second = i;
    }
    REP(i, 0, w){
        W[i].second = i;
    }
    REP(i, 0, m){
        ll x, y; cin >> x >> y;
        x--; y--;
        H[x].first++;
        W[y].first++;
        mp[Pii(x, y)]++;
    }
    sort(ALL(H), [](auto &x, auto &y){return x.first > y.first;});
    sort(ALL(W), [](auto &x, auto &y){return x.first > y.first;});
    ll Hmax = H[0].first, Wmax = W[0].first, i = 0;
    //cout << Hmax << Wmax << endl;
    ll ans = 0;
    while(i < h && Hmax - H[i].first < 1){
        int l = 0;
        while(l < w &&  Wmax - W[l].first < 1){
            if(mp[Pii(H[i].second, W[l].second)] == 1){
                chmax(ans, H[i].first + W[l].first - 1);
            }else{
                cout << H[i].first + W[l].first << endl;
                return 0;
            }
            l++;
        }
        i++;
    }
    cout << ans << endl;
}