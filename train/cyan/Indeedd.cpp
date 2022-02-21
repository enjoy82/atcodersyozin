// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
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
    ll n, c; cin >> n >> c;
    vector<vector<ll> > lis(c);
    REP(i, 0, n){
        ll a; cin >> a; a--;
        lis[a].pb(i);
    }
    ll sum = (n * (n+1)) / 2;
    REP(i, 0, c){
        ll pre = -1;
        ll count = 0;
        REP(l, 0, lis[i].size()){
            ll next = lis[i][l];
            ll k = max(next - pre - 1, 0LL);
            count += (k * (k+1)) / 2;
            pre = next;
        }
        ll k = max(n - pre - 1 , 0LL);
        count += (k * (k+1)) / 2;
        cout << sum - count << endl;
    }
}