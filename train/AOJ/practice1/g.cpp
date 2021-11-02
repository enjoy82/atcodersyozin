// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include <bits/stdc++.h>
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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

#define REP(i, l, n) for(int i = (l), i##_len = (n); i < i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define pb push_back

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts>
inline auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

// dp[i][j][ii][jj][turn][pass] :=

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> alis(n), blis(m), ruisekia(n + 1, 0), ruisekib(m + 1, 0);
    REP(i, 0, n) { cin >> alis[i]; }
    REP(i, 0, m) { cin >> blis[i]; }
    REP(i, 0, n) {
        ruisekia[i + 1] = ruisekia[i] + alis[i];
    }
    REP(i, 0, m) {
        ruisekib[i + 1] = ruisekib[i] + blis[i];
    }
    auto dp = make_vec(n + 1, m + 1, n + 1, m + 1, 2, 2, 2, -1e9);
    ll ans = -2e9;
    dp[0][0][0][0][0][0][0] = 0;
    REP(i, 0, n) {                     //topの位置
        REP(l, 0, m) {                 //topの位置
            REP(k, 0, n + 1) {         //有効なスタックのtopの位置
                REP(m, 0, m + 1) {     //有効なスタックのtopの位置
                    REP(a, 0, 2) {     //turn
                        REP(b, 0, 2) { //passflag
                            if(dp[i][l][k][m][a][b][0] == -1e9)
                                continue;
                            if(a == 0) { //p1
                                //passするとき スコア計算
                                cout << "p1 " <<  i << l << " " << dp[i][l][k][m][a][b][0] << endl;
                                chmax(dp[i][l][i][l][1][1][0], -1 * (dp[i][l][k][m][a][b][0] + (ruisekia[i] - ruisekia[k]) - (ruisekib[l] - ruisekib[m])));
                                //カード出す時
                                if(alis[i] == -1) {
                                    chmax(dp[i + 1][l][i + 1][l][1][1][0], -1 * dp[i][l][k][m][a][b][0]);
                                } else {
                                    chmax(dp[i + 1][l][k][m][1][0][0], -1 * dp[i][l][k][m][a][b][0]);
                                }
                                chmax(dp[i][l][i][l][a][b][0], (dp[i][l][k][m][a][b][0] + (ruisekia[i] - ruisekia[k]) - (ruisekib[l] - ruisekib[m])));
                            }else{ //p2
                                cout << "p2 " << i << l << " " << dp[i][l][k][m][a][b][0] << endl;
                                //passするとき スコア計算
                                chmax(dp[i][l][i][l][0][1][0], -1 * (dp[i][l][k][m][a][b][0] + (ruisekia[i] - ruisekia[k]) - (ruisekib[l] - ruisekib[m])));
                                //カード出す時
                                if(blis[i] == -1) {
                                    chmax(dp[i][l + 1][i][l + 1][0][1][0], -1 * dp[i][l][k][m][a][b][0]);
                                } else {
                                    chmax(dp[i][l + 1][k][m][0][0][0], -1 * dp[i][l][k][m][a][b][0]);
                                    chmax(dp[i][l + 1][k][m][0][0][0], -1 * dp[i][l][k][m][a][b][0]);
                                }
                                chmax(dp[i][l][i][l][a][b][0], (dp[i][l][k][m][a][b][0] + (ruisekia[i] - ruisekia[k]) - (ruisekib[l] - ruisekib[m])));
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}