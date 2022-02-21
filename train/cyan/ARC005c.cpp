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
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    REP(i, 0, h){cin >> grid[i];}
    vector<vector<int> > lis(h, vector<int>(w, 1e9));
    int sx, sy, gx, gy;
    REP(i, 0, h){
        REP(l, 0, w){
            if(grid[i][l] == 's'){
                sx = i, sy = l;
            }
            if(grid[i][l] == 'g'){
                gx = i, gy = l;
            }
        }
    }
    lis[sx][sy] = 0;
    queue<Pii> que1, que2, que3;
    que1.push(Pii(sx,sy));
    while(1){
        while(!que1.empty()){
            Pii now = que1.front();
            que1.pop();
            int x = now.first, y = now.second;
            REP(i, 0, 4){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < h && ny >= 0 && ny < w){
                    if(grid[nx][ny] == '#' && chmin(lis[nx][ny], lis[x][y] + 1)){
                        que2.push(Pii(nx, ny));
                    }else if((grid[nx][ny] == 'g' || grid[nx][ny] == '.') && chmin(lis[nx][ny], lis[x][y])){
                        que1.push(Pii(nx, ny));    
                    }
                } 
            }
        }
        if(que2.empty()){
            break;
        }
        que1 = que2;
        que2 = que3;
    }
    /*REP(i, 0, h){
        REP(l, 0, w){
            cout << lis[i][l];
        }
        cout << endl;
    }*/
    if(lis[gx][gy] > 2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}