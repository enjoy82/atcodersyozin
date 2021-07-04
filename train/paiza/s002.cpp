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
    int w, h; cin >> w >> h;
    vector<vector<int> > grid(h, vector<int> (w, 0));
    int sx, sy, gx, gy;
    REP(i,0,h){
        REP(l,0,w){
            char a; cin >> a;
            if(a == '0'){
                grid[i][l] = 0;
            }else if(a == '1'){
                grid[i][l] = 1;
            }else if(a == 's'){
                grid[i][l] = 2;
                sx = i;
                sy = l;
            }else{
                grid[i][l] = 3;
                gx = i;
                gy = l;
            }
        }
    }
    vector<vector<int> > dp(h, vector<int>(w, 1e9));
    dp[sx][sy] = 0;
    queue<Pii> que;
    que.push(Pii(sx, sy));
    while(!que.empty()){
        Pii now = que.front();
        que.pop();
        int x = now.first, y = now.second;
        REP(i,0,4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] != 1 && dp[nx][ny] > dp[x][y] + 1){
                chmin(dp[nx][ny], dp[x][y] + 1);
                que.push(Pii(nx, ny));
            }
        }
    }
    if(dp[gx][gy] == 1e9){
        cout << "Fail" << endl;
        return 0;
    }
    cout << dp[gx][gy] << endl;
}