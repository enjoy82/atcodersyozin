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
    ll n, x, m; cin >> n >> x >> m;
    ll ans = 0, s = x;
    ll now = x;
    vector<ll> hato(m+1, 0);
    REP(i, 0, m-1){
        hato[x] = (x * x) % m;
        x =  (x * x) % m;
    }
    ll mid = 0, mid1 = 0;
    vector<int> flag(m+1, 0);
    while(1){
        if(flag[now] == 1){
            break;
        }else{
            flag[now] = 1;
            mid += hato[now];
            now = hato[now]; 
        }
    }
    vector<int> flag1(m+1, 0);
    ll count = 0;
    while(1){
        if(flag1[now] == 1){
            break;
        }else{
            flag1[now] = 1;
            mid1 += hato[now];
            now = hato[now]; 
            count++;
        }
    }
    REP(i, 0, n){
        ans += s;
        s = hato[s];
        if(s == now){
            ll k = max(0LL, (n-(i+1LL)) / count);
            ans += k * mid1;
            i += count * k;
        }
    }
    cout << ans << endl;
}