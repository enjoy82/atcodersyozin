// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//ordered_set 重複不可
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

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

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示
const long long INF = 1LL<<60;

// 最長増加部分列の長さを求める
int solve(vector<long long> &a) {
    int n = (int)a.size();
    vector<int> lsize(n);
    vector<long long> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        // dp[k] >= a[i] となる最小のイテレータを見つける
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);

        // そこを a[i] で書き換える
        *it = a[i];
        lsize[i] = lower_bound(ALL(dp), INF) - dp.begin();
    }

    int ans = 0;
    reverse(ALL(a));
    vector<long long> dp2(n, INF);
    for (int i = 0; i < n; ++i) {
        // dp[k] >= a[i] となる最小のイテレータを見つける
        auto it = lower_bound(dp2.begin(), dp2.end(), a[i]);

        // そこを a[i] で書き換える
        *it = a[i];
        int k = lower_bound(ALL(dp2), INF) - dp2.begin();
        chmax(ans, k + lsize[n-i-1]-1);
    }
    // dp[k] < INF となる最大の k に対して k+1 が答え
    // それは dp[k] >= INF となる最小の k に一致する
    return ans;
}

int main() {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << solve(a) << endl;
}   