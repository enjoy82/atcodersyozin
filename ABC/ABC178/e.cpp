// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
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

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n; cin >> n;
    ll ans = 0;
    vector<vector<ll> > dist(n, vector<ll>(3));
    vector<ll> xlis(n), ylis(n);
    REP(i, 0, n){
        cin >> xlis[i] >> ylis[i];
        dist[i][0] = xlis[i] + ylis[i];
        dist[i][1] = xlis[i] - ylis[i];
        dist[i][2] = i;
    }
    sort(ALL(dist), [](auto &x, auto &y){return x[0] < y[0];});
    REP(i, 0, n){
        int key = dist[i][2];
        REP(l, 0, min(n, 10)){
            int key1= dist[l][2], key2 = dist[n-1 - l][2];
            chmax(ans, abs(xlis[key] - xlis[key1]) + abs(ylis[key] - ylis[key1]));
            chmax(ans, abs(xlis[key] - xlis[key2]) + abs(ylis[key] - ylis[key2]));
        }
    }
    sort(ALL(dist), [](auto &x, auto &y){return x[1] > y[1];});
    REP(i, 0, n){
        int key = dist[i][2];
        REP(l, 0, min(n, 10)){
            int key1= dist[l][2], key2 = dist[n-1 - l][2];
            chmax(ans, abs(xlis[key] - xlis[key1]) + abs(ylis[key] - ylis[key1]));
            chmax(ans, abs(xlis[key] - xlis[key2]) + abs(ylis[key] - ylis[key2]));
        }
    }
    cout << ans << endl;
}