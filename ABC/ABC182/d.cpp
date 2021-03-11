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

int main(){
    int n; cin >> n;
    vector<ll> lis(n), ruiseki(n+1, 0);
    ll ans = -1, mid = 0, idx = 0, mid1 = 0;
    REP(i, 0, n){
        cin >> lis[i];
    }
    REP(i, 0, n){
        ruiseki[i+1] = ruiseki[i] + lis[i];
    }
    REP(i, 0, n+1){
        mid += ruiseki[i];
        if(ans <= mid){
            chmax(ans, mid);
            idx = i;
        }
    }
    mid1 = ans;
    ll mid2 = ans;
    for(int i = idx - 1; i >= 0; i--){
        mid1 -= lis[i];
        chmax(ans, mid1);
    }
    REP(i, 0, idx+1){
        if(idx == n){
            break;
        }
        mid2 += lis[i];
        chmax(ans, mid2);
    }
    cout << max(ans, 0LL) << endl;
}