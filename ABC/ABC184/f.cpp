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
#define int long long
#define int ll

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

signed main() {
    // 入力
    ll N, S;
    cin >> N >> S;
    vector<ll> num(N);
    for (ll i = 0; i < N; i++) {
        cin >> num.at(i);
    }
    // グループ１をビット全探索で全列挙 (前半の半分)
    vector<ll> A;
    for (int bit = 0; bit < (1 << (N+1) / 2); bit++) {
        ll sum = 0;
        for (int i = 0; i < ((N+1) / 2); i++) {
            int mask = 1 << i;
            if (bit & mask) {
                sum += num[i];
            }
        }
        A.push_back(sum);
    }
    // グループ2をビット全探索で全列挙 (後半の半分)
    vector<ll> B;
    for (int bit = 0; bit < (1 << N / 2); bit++) {
        ll sum = 0;
        for (ll i = 0; i < (N / 2); i++) {
            int mask = 1 << i;
            if (bit & mask) {
                sum += num[(N+1) / 2 + i];
            }
        }
        B.push_back(sum);
    }
    sort(B.begin(), B.end());  // B をソート
    // A の要素を固定して二分探索
    ll ans = 0;
    for (auto a : A) {
        if (S - a >= 0) {
            ans = max(ans, a + *(upper_bound(B.begin(), B.end(), S - a) - 1));
        }
    }
    cout << ans << endl;
    return 0;
}