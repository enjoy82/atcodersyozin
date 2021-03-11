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
    int n, m; cin >> n >> m;
    vector<ll> lis(n), wlis(m), dif1, dif2, difi1(n/2+1, 0), difi2(n/2+1, 0);
    REP(i, 0, n){
        cin >> lis[i];
    }
    REP(i, 0, m){
        cin >> wlis[i];
    }
    ll ans = 1e17;
    sort(ALL(lis));
    for(int i = 0; i < n-1; i += 2){
        dif1.pb(abs(lis[i+1] - lis[i]));
    }
    REP(i, 0, difi1.size() - 1){
        difi1[i+1] = difi1[i] + dif1[i];
    }
    for(int i = 1; i < n-1; i += 2){
        dif2.pb(abs(lis[i+1] - lis[i]));
    }
    REP(i, 0, difi2.size() - 1){
        difi2[i+1] = difi2[i] + dif2[i];
    }
    REP(i, 0, m){
        auto it = lower_bound(ALL(lis), wlis[i]);
        int k = it - lis.begin();
        if(k == 0){
            chmin(ans, difi2.back() + abs(wlis[i] - lis[0]));
        }else if(k == n){
            chmin(ans, difi1.back() + abs(wlis[i] - lis.back()));
        }else if(k % 2 == 1){
            ll mid1 = difi2.back() - difi2[k/2], mid2 = difi1[k/2];
            chmin(ans, mid1 + mid2 + abs(wlis[i] - lis[k-1]));
        }else{
            ll mid1 = difi2.back() - difi2[k/2], mid2 = difi1[k/2];
            chmin(ans, mid1 + mid2 + abs(wlis[i] - lis[k]));
        }
    }
    cout << ans << endl;
}