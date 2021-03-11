// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace atcoder;

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
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll mod = 1e9 + 7;

void solve(){
    ll n, a, b; cin >> n >> a >> b;
    if(b < a){
        ll x = a; a = b; b = x;
    }
    ll k = (n-a-b);
    ll c = (k-1)*(k*(k+1)/2), c1 = (k*(k+1)*(2*k+1)) / 6;
    ll ans = (n-a) * (n-b) * 2 * (k+1+c - c1);
    ll ck = (k*(k+1)/2), ckk = (k*(k+1)*(2*k+1)) / 6, ckkk = ck * ck, ckkkk = k * (k+1) * (2*k+1) * (3*k*k + 3*k - 1) / 30;
    
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}