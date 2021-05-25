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

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<Pii> pos(n+1);
    vector<string> grid(h);
    REP(i,0,h){cin >> grid[i];}
    REP(i,0,h){
        REP(l,0,w){
            if(grid[i][l] == 'S'){
                pos[0] = Pii(i, l);
            }else if(grid[i][l] - '0' >= 0 && grid[i][l] - '0' <= 9){
                pos[grid[i][l]-'0'] = Pii(i, l);
            }
        }
    }
    int ans = 0;
    REP(i,0,n){
        int sx = pos[i].first, sy = pos[i].second;
        int gx = pos[i+1].first, gy = pos[i+1].second;
        queue<Pii> que;
        que.push(Pii(sx, sy));
        vector<vector<int> > val(h, vector<int>(w, 1e9));
        val[sx][sy] = 0;
        while(!que.empty()){
            Pii now = que.front();
            int x = now.first, y = now.second;
            que.pop();
            REP(l,0,4){
                int nx = x + dx[l], ny = y + dy[l];
                if(nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] != 'X' && val[nx][ny] > val[x][y] + 1){
                    val[nx][ny] = val[x][y] + 1;
                    que.push(Pii(nx, ny));
                }
            }
        }
        ans += val[gx][gy];
    }
    cout << ans << endl;
}