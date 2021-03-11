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

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int main(){
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    REP(i, 0, h){cin >> grid[i];}
    vector<vector<Pii>> alpos(26);
    int sx, sy, gx, gy;
    REP(i, 0, h){
        REP(l, 0, w){
            if(grid[i][l] == 'S'){
                sx = i;
                sy = l;
            }
            if(grid[i][l] == 'G'){
                gx = i;
                gy = l;
            }
            if(grid[i][l] - 'a' >= 0 && grid[i][l] - 'a' < 26){
                alpos[grid[i][l] - 'a'].pb(Pii(i, l));
            }
        }
    }
    queue<Pii> que;
    vector<int> alflag(26, 0);
    que.push(Pii(sx, sy));
    vector<vector<int>> flag(h, vector<int>(w, 1e9));
    flag[sx][sy] = 0;
    while(!que.empty()){
        Pii now = que.front();
        que.pop();
        int x = now.first, y = now.second;
        int count = flag[x][y];
        if(grid[x][y] - 'a' >= 0 && grid[x][y] - 'a' < 26){
            int num = grid[x][y] - 'a';
            if(alflag[num] == 0){
                REP(i, 0, alpos[num].size()){
                    int nx = alpos[num][i].first, ny = alpos[num][i].second;
                    if(flag[nx][ny] > count+1){
                        flag[nx][ny] = count + 1;
                        que.push(Pii(nx, ny));
                    }
                }
                alflag[num] = 1;
            }
        }
        REP(i, 0, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] != '#' && flag[nx][ny] > count+1){
                flag[nx][ny] = count + 1;
                que.push(Pii(nx, ny));
            }
        }
    }
    if(flag[gx][gy] == 1e9){
        cout << -1 << endl;
        return 0;
    }
    cout << flag[gx][gy] << endl;
}