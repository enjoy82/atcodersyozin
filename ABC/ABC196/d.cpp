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

int dx[2] = {1, 0};
int dy[2] = {0, 1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int h, w, a, b; 

vector<vector<vector<Pii>>> gridmemo;
vector<vector<vector<Pii>>> gridmemo2;

void solve(vector<vector<Pii>> grid, int x, int  y, int count){
    if(x+1 == h && y+1 == w){
        if(count == a){
            gridmemo.pb(grid);
        }else{
            return;
        }
    }else if(x+1 == h){
        solve(grid, 0, y+1, count);
    }else{
        solve(grid, x+1, y, count);
    }
    REP(i,0,2){
        int nx = x + dx[i], ny = y+dy[i];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == Pii(-1, -1) && grid[x][y] == Pii(-1, -1)){
            grid[x][y] = Pii(nx, ny);
            grid[nx][ny] = Pii(x, y);
            if(x+1 == h && y+1 == w){
                if(count+1 == a){
                    gridmemo.pb(grid);
                }else{
                    return;
                }
            }else if(x+1 == h){
                solve(grid, 0, y+1, count+1);
            }else{
                solve(grid, x+1, y, count+1);
            }
            grid[x][y] = Pii(-1, -1);
            grid[nx][ny] = Pii(-1, -1);
        }
    }
}

int main(){
    cin >> h >> w >> a >> b;
    vector<vector<Pii> > grid(h, vector<Pii>(w, Pii(-1, -1)));
    int ans = 0;
    solve(grid, 0, 0, 0);
    /*
    REP(i, 0, gridmemo.size()){
        REP(x, 0,h){
            REP(y, 0, w){
                cout << gridmemo[i][x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    */
    REP(i,0,gridmemo.size()){
        int flag = 1;
        REP(l, 0, gridmemo2.size()){
            int f = 1;
            REP(x, 0, h){
                REP(y, 0, w){
                    if(gridmemo[i][x][y] != gridmemo2[l][x][y]){
                        f = 0; //OK
                    }
                }
            }
            if(f){
                flag = 0;
            }
        }
        if(flag){
            gridmemo2.pb(gridmemo[i]);
        }
        ans += flag;
    }
    cout << ans << endl;
}