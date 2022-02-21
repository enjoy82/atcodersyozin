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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> hlis(n);
    REP(i, 0, n){cin >> hlis[i];}
    sort(ALL(hlis));
    ll left = 0, right = 1e10;
    while(right - left > 1){
        vector<ll> cp = hlis;
        ll mid = (right + left) / 2;
        //cout << mid << endl;
        ll have = mid;
        REP(i, 0, n){
            have -= (max(0LL, cp[i] - (mid * b)) + (a-b-1)) / (a-b);
        }
        if(have < 0){
            left = mid;
        }else{
            right = mid;
        }
    }
    ll have = left;
    REP(i, 0, n){
        have -= (max(0LL, hlis[i] - (left * b)) + (a-b-1)) / (a-b);
    }
    if(have < 0){
        cout << right << endl;
        return 0;
    }else{
        cout << left << endl;
        return 0;
    }
}