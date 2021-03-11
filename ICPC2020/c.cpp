// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

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

map<ll, ll> mp;
vector<vector<ll> >memo(1e6);
int co = 0;

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

void solve(ll x){
    vector<ll> r = divisor(x);
    ll ans = 1e18;
    REP(i, 0, r.size()){
        ll c = r[i];
        ll mid = x / c;
        vector<ll> r1;
        if(mp.count(mid)){
            r1 = memo[mp[mid]];
        }else{
            r1 = divisor(mid);
            mp[mid] = co;
            memo[co] = r1;
            co++;
        }
        int size = r1.size();
        if(r1.size() % 2 == 1){
            chmin(ans, c + r1[size / 2] + (mid / r1[size / 2]));
        }else{
            chmin(ans, c + r1[size / 2] + (mid / r1[size / 2]));
            chmin(ans, c + r1[size / 2 - 1] + (mid / r1[size / 2 - 1]));
        }
    }
    cout << ans << endl;
}

int main(){
    ll x; 
    while(1){
        cin >> x;
        if(x == 0){
            return 0;
        }
        solve(x);
    }
}