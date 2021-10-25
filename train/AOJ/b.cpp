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

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[6] = {1, 1, 0, -1, -1, 0};
int dy[6] = {1, 0, -1, -1, 0, 1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int main() {
    int t;
    while(cin >> t) {
        int n;
        cin >> n;
        if(t == 0 && n == 0)
            break;
        vector<vector<int>> used(150, vector<int>(150, -1));
        REP(i, 0, n) {
            int x, y;
            cin >> x >> y;
            used[x + 60][y + 60] = -2;
        }
        queue<Pii> que;
        int sx, sy;
        cin >> sx >> sy;
        sx += 60;
        sy += 60;
        que.push(Pii(sx, sy));
        used[sx][sy] = t;
        while(!que.empty()) {
            Pii a = que.front();
            int x = a.first, y = a.second;
            que.pop();
            REP(l, 0, 6) {
                int nx = x + dx[l], ny = y + dy[l];
                if(used[nx][ny] != -2 && used[x][y] >= 1) {
                    if(chmax(used[nx][ny], used[x][y] - 1) && used[nx][ny] > 0) {
                        que.push(Pii(nx, ny));
                    }
                }
            }
        }
        int ans = 0;
        REP(i, 0, 150) {
            REP(l, 0, 150) {
                if(used[i][l] >= 0)
                    ans++;
            }
        }
        cout << ans << endl;
    }
}